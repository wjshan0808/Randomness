#!/usr/bin/env bash

# ls -l `which sh` --> dash 不支持 if [[ 语法

# 检查参数个数
if [ $# -ne 2 ]; then
    echo " Invalid parameters = $# ... "
    exit 1
else
    echo " srcPath = $1 "
    echo " dstPath = $2 "
fi

# find $1 -name '*.h' | cpio -pvudm $2
# find $1 -name '*.h' -exec cp -r {} $2 \;
# 安装头文件
#function 
installHeaderFiles() {

    # 参数变量
    local srcPath=$1
    local dstPath=$2
    echo " local srcPath = $srcPath "
    echo " local dstPath = $dstPath "

    # 取当前层目录 与 目标路径拼接 构建目标路径 {##从左贪心删除 *任意字符 /最终包含符}
    local mkdirPath="${dstPath}/${srcPath##*/}"

    # 创建目标路径
    if [ ! -d $mkdirPath ]; then
        echo "  mkdir = $mkdirPath "
        mkdir -p $mkdirPath
    fi

    # 遍历当前层目录结构
    for itemFile in `ls $srcPath`; do

        # 跳过系统目录
        if [[ $itemFile != "." && $itemFile != ".." ]]; then

            # 构建原始文件项路径
            local itemSrcPath="${srcPath}/${itemFile}"

            #
            if [[ -d $itemSrcPath ]]; then

                # 递归调用
                installHeaderFiles $itemSrcPath $mkdirPath

            else

                # 复制头文件 ~正则匹配
                if [[ "${itemFile##*.}" =~ ^h.*$ ]]; then
                    echo "  cp -f $itemSrcPath $mkdirPath "
                    cp -f $itemSrcPath $mkdirPath
                fi
                
            fi

        fi

    done

}

echo " begin post build ... "
    installHeaderFiles $1 $2
echo " end post build ... "
