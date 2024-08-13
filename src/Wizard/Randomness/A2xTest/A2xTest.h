#ifndef _H_A2X_TEST_H_
#define _H_A2X_TEST_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Randomness_Global.h"
#include "../A2xKits/A2xKits.h"
#include "externs.h"


#define FLAG_SUCCESS    (0x01)
#define FLAG_FAILURE    (0x00)

#if defined(__cplusplus)
extern "C" {
#endif

/* GM;NIST */

/*
 * 近似熵 m=[2,5];[10]
 * */
int // void
RANDOMNESS_EXPORT
ApproximateEntropy(int m, int n, BitSequence *epsilon);
/*
 * 二元推导 k=[3,7];
 * */
RANDOMNESS_EXPORT
int // void
BinaryDerivate(int k, int n, BitSequence *epsilon);
/*
 * 块频数 M=[100];[128]
 * */
RANDOMNESS_EXPORT
int // void
BlockFrequency(int M, int n, BitSequence *epsilon);
/*
 * 累加和
 * */
RANDOMNESS_EXPORT
int // void
CumulativeSums(int n, BitSequence *epsilon);
/*
 * 离散傅立叶
 * */
RANDOMNESS_EXPORT
int // void
DiscreteFourierTransform(int n, BitSequence *epsilon);
/*
 * 比特频数
 * */
RANDOMNESS_EXPORT
int // void
Frequency(int n, BitSequence *epsilon);
/*
 * 线性复杂度 M=;[500];
 * */
RANDOMNESS_EXPORT
int // void
LinearComplexity(int M, int n, BitSequence *epsilon);
/*
 * 块内最大1游程
 * */
RANDOMNESS_EXPORT
int // void
LongestRunOfOnes(int n, BitSequence *epsilon);
/*
 * 非重叠模版匹配 m=;[9], 需要"templates/template%d"数据
 * */
RANDOMNESS_EXPORT
int // void
NonOverlappingTemplateMatchings(int m, int n, BitSequence *epsilon);
/*
 * 重叠模版匹配 m=;[9]
 * */
RANDOMNESS_EXPORT
int // void
OverlappingTemplateMatchings(int m, int n, BitSequence *epsilon);
/*
 * 扑克 M=[4,8];
 * */
RANDOMNESS_EXPORT
int // void
PokerDetect(int M, int n, BitSequence *epsilon);
/*
 * 自由游程
 * */
RANDOMNESS_EXPORT
int // void
RandomExcursions(int n, BitSequence *epsilon);
/*
 * 自由变量
 * */
RANDOMNESS_EXPORT
int // void
RandomExcursionsVariant(int n, BitSequence *epsilon);
/*
 * 矩阵秩
 * */
RANDOMNESS_EXPORT
int // void
Rank(int n, BitSequence *epsilon);
/*
 * 游程总数
 * */
RANDOMNESS_EXPORT
int // void
Runs(int n, BitSequence *epsilon);
/*
 * 游程分布
 * */
RANDOMNESS_EXPORT
int // void
RunsDistribution(int n, BitSequence *epsilon);
/*
 * 自相关 d=[1,2,8,16];
 * */
RANDOMNESS_EXPORT
int // void
SelfCorrelation(int d, int n, BitSequence *epsilon);
/*
 * 重叠子序列 m=[2,5]；sha-1=[16]
 * */
RANDOMNESS_EXPORT
int // void
Serial(int m, int n, BitSequence *epsilon);
/*
 * 通用统计
 * */
RANDOMNESS_EXPORT
int // void
Universal(int n, BitSequence *epsilon);


#if defined(__cplusplus)
}
#endif

#endif /* !_H_A2X_TEST_H_ */
