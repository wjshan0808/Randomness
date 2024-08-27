#!/usr/bin/env bash

# 打包
# tar -cvzf install_modules.tar.gz libXXX.a libXXX.so XXX.ko 大
# tar -cvjf install_modules.tar.bz2 libXXX.a libXXX.so XXX.ko 小

# 制作 bin/run
# cat target.sh target.tar > target.bin/run
# sudo chmod u+x target.bin/run
# sudo chown root target.bin/run
# sudo chmod a+s target.bin/run

# 变量 $(sed -n "$=" $0)
shLines=61
#extractFileName=install_modules.tar.gz
extractFileName=install_modules.tar.bz2
extractDirectory=/tmp/XXX_modules
extractFile="${extractDirectory}/${extractFileName}"
moduleName=XXX
moduleSOFileName=libXXX.so

#
mkdir -p "${extractDirectory}"

# 提取 run
# -n 跳过标识
# +NUM 行数NUM
# 即跳过 +NUM 减一行 #
#tail -n +${shLines} "$0" > ${extractFile} 2>/dev/null

# 提取 bin
# -n 取消 'p' 的 $0 自身文件内容打印,
# ’1,/^exit 0$/' 从第一行正则匹配到行为止的所有内容,
# ! 反向即 $0 文件自身匹配内容后面的内容
# > 输出到
# 2> 显示输出到
sed -n -e '1,/^exit 0$/'!p "$0" > ${extractFile} 2>/dev/null

echo "sth doing ..."

# 解压 --strip-components 1
#tar -xzf ${extractFile} -C "${extractDirectory}"
tar -xjf ${extractFile} -C "${extractDirectory}"

#
sudo cp -f "${extractDirectory}/${moduleSOFileName}" /lib/

if [[ ${moduleName} == $(lsmod | grep ${moduleName} | awk '{ print $1 }') ]]
then
    sudo rmmod ${moduleName}
fi
sudo insmod "${extractDirectory}/${moduleName}.ko"

#
rm -rf "${extractDirectory}"

echo "sth done ..."

# 结束 要留LF空行
exit 0
