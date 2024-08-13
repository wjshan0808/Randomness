#ifndef C_RANDOMNESS_H
#define C_RANDOMNESS_H

#include "Randomness_Global.h"
#include "A2xTest/A2xTest.h"


#if defined(__cplusplus)
extern "C" {
#endif

RANDOMNESS_EXPORT int TestRandomnessExport(int iValue);

RANDOMNESS_EXPORT int BytesToBitSequence(unsigned char *in, int inl, BitSequence *outbuf, int bufsize);

#if defined(__cplusplus)
}
#endif


class RANDOMNESS_EXPORT CRandomness
{
public:
    explicit CRandomness();
    virtual ~CRandomness();

public:
    int TestRandomnessExport(int iValue);
};


#endif // !C_RANDOMNESS_H
