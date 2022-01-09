#include "Prime.h"
//Although it's not fully correct mathematicaly - 
//but assigning the first prime value to 1, true ensures the correctness of the next actions
//This comment is not in the format of doxygen because the previous prime value is a sensitive info
//and the developer doesn't want to let the user know this variable exists at all
Prime64Bit previousPrime = { 1, true };

/// <summary>
/// As it was told in the task this function is for the internal use only,
/// therefore it should not be declared in header file.
/// The functions checks whether the number can be divided by any of
/// the numbers till it's half (if it's not there is no need to check 
/// the next numbers because the result can't be whole number
/// </summary>
/// <param name="number"></param>
/// <returns></returns>
bool IsPrime(uint64_t number)
{
    for (uint64_t i = 2; i <= number/2; i++)
    {
        if((number%i)==0)
            return false;
    }
    return true;
}

Prime64Bit GetNextPrime()
{
    uint64_t i;
    Prime64Bit result;
    if (previousPrime.notOverflowed) {
        if (previousPrime.prime > 2)
            i = previousPrime.prime + 2;
        else
        {
            previousPrime.prime = previousPrime.prime++;
            return previousPrime;
        }
        for (; i < UINT64_MAX; i++)
        {
            if (IsPrime(i))
            {
                previousPrime.prime = i;
                return previousPrime;
            }
        }
        //the next prime is larger than the max value uint64_t can hold
        previousPrime.notOverflowed = false;
    }
    previousPrime.notOverflowed = false;
    return previousPrime;
}

/// <summary>
/// The function for the test needs only, shoukd not be exported in any case
/// because it can check the sensitive info and the program won't work correctly
/// afterwards.
/// It makes no validity checks because the test will somewhere need to put 
/// a not very valid values
/// </summary>
/// <param name="notValidatedValue"></param>
void setPreviousPrimeValue(uint64_t notValidatedValue)
{
    previousPrime.prime = notValidatedValue;
}

/// <summary>
/// The function for the test needs only, shoukd not be exported in any case
/// because it can check the sensitive info and the program won't work correctly
/// afterwards.
/// It makes no validity checks because the test will somewhere need to put 
/// a not very valid values
/// </summary>
/// <param name="notValidatedValue"></param>
void setPreviousPrimeValidity(bool notValidatedValue)
{
    previousPrime.notOverflowed = notValidatedValue;
}