#include <stdio.h>
#include "Prime.h"
/// <summary>
/// The function that runs the GetNextPrime() once and prints the next prime's
/// value in case the result is valid or notifies that the overflow happened otherwise
/// </summary>
void onePrimePrintFunction()
{
	Prime64Bit prime = GetNextPrime();
	if (prime.notOverflowed)
	{
		printf("%"PRIu64"\n", prime.prime);
	}
	else printf("Overflow\n");
}

/// <summary>
/// Gets and prints first 150 prime numbers
/// </summary>
void basicTest()
{
	printf("Basic test for generating a row of integers\n");
	for (uint64_t i = 0; i < 150; i++)
	{
		onePrimePrintFunction();
	}
	printf("_____________________________________________\n");

}

/// <summary>
/// The function causes integer overflow case and prints the result of GetNextPrime()
/// Which should notify that the result is invalid
/// </summary>
void overflowingIntegerTest()
{
	printf("Integer Overflow Generating Test\n");
	setPreviousPrimeValue(UINT64_MAX - 2);
	setPreviousPrimeValidity(true);
	onePrimePrintFunction();
	printf("_____________________________________________\n");
}

/// <summary>
/// Starts with not valid previousPrime Value to check that the result 
/// of GetNextPrime in this case will be invalid too
/// </summary>
void notValidLastPrime()
{
	printf("Not Valid Last Prime Test\n");
	setPreviousPrimeValue(17);
	setPreviousPrimeValidity(false);
	onePrimePrintFunction();
	printf("_____________________________________________\n");
}

/// <summary>
/// main function to run all the tests
/// </summary>
/// <returns></returns>
int main()
{
	//Basic test to ensure the functions work with first 150 numbers
	basicTest();

	//The test to ensure we can catch integeroverflow case
	overflowingIntegerTest();

	//The test to ensure that if the overflow happened 
	//in future the program won't generate the same primes in loop
	notValidLastPrime();
	
	//No need to test, for example, negative numbers assignment - the user can't do that because the Prime64Bit uses an unsigned type
	//Andin any case, the user cant set the values for the prime in any case.
	//On the other hand, the overflow cases can happen themselves during the program's work.
	return 0;
}
