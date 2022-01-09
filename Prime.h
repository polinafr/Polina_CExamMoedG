#ifndef PRIME_H
#define PRIME_H
#include <stdbool.h>
#include <inttypes.h>
/// <summary>
/// struct Prime64Bit is the wrapper for the prime number value.
/// The prime number value itself is represented by uint64_t
/// as the big enough cross-platform type of integer - 64 bits (probably not enough for cryptographic uses) represented 
/// in the C libraries, with no sign because the task is to start generating prime numbers from 2.
/// It also containes an additional field to ensure that the value has not overflowed the size of the variable
/// that ensures the case of overflow can be caught and would not be treated as a legal result. 
/// However, the algorithm doesn't enable to generate primes greater than UINT64_MAX (2^64-1)
/// </summary>
typedef struct prime64Bit
{
	uint64_t prime;
	bool notOverflowed;
} Prime64Bit;

/// <summary>
/// @brief The function generates and returns the next prime number
/// 
/// </summary>
/// <returns>The next prime number after the last one returned, up to 64 bits</returns>
Prime64Bit GetNextPrime();
//The next two functions needed to testing the code only, therefore shoukd be ommited from code after tests
//Otherwise, they can enable the user to change the sensitive data
void setPreviousPrimeValue(uint64_t notValidatedValue);
void setPreviousPrimeValidity(bool notValidatedValue);
#endif
