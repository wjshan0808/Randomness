/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
              U T I L I T Y  F U N C T I O N  P R O T O T Y P E S 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef _C_UTILITIES_H_
#define _C_UTILITIES_H_

#include <stdio.h>
#include "config.h"

#if defined(__cplusplus)
extern "C" {
#endif

void	readHexDigitsInBinaryFormat(FILE *fp);
int		displayGeneratorOptions();
int		generatorOptions(char** streamFile);
void	chooseTests();
void	fixParameters();
void	fileBasedBitStreams(char *streamFile);
void	readBinaryDigitsInASCIIFormat(FILE *fp, char *streamFile);
int		convertToBits(BYTE *x, int xBitLength, int bitsNeeded, int *num_0s, int *num_1s, int *bitsRead);
void	openOutputStreams(int option);
void	invokeTestSuite(int option, char *streamFile);
void	nist_test_suite();

#if defined(__cplusplus)
}
#endif

#endif /* !_C_UTILITIES_H_ */
