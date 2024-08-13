#include "Randomness.h"
//#include "A2xTest/A2xTest.h"


int TestRandomnessExport(int iValue)
{
    return (__INT_MAX__ & iValue);
}


CRandomness::CRandomness()
{

}
CRandomness::~CRandomness()
{

}


int CRandomness::TestRandomnessExport(int iValue)
{
    return (__INT_MAX__ & iValue);
}
