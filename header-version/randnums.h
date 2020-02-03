#ifndef RANDNUMS_H_
#define RANDNUMS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*

Six powerfull functions to get random numbers, see the menu() function bellow to learn how to use each of them...

randomIntegers -> returns an array of random integers according to the parameters passed.
randomFloats -> returns an array of random floats according to the parameters passed.
randomInt -> returns a random integer according to the parameters passed.
randomFloat -> returns a random float according to the parameters passed.
randomStringInteger -> returns a random integer (as a string) made out of individual random digits according to the parameters passed.
randomStringInteger -> returns a random float (as a string) made out of individual random digits according to the parameters passed.

*/

long int *randomIntegers(unsigned long long amount, long int min, long int max);
long double *randomFloats(unsigned long long amount, long double min, long double max);
long int randomInt(long int min, long int max);
long double randomFloat(long double min, long double max);
char *randomStringInteger(unsigned long long digits, unsigned int firstDigitAbove, unsigned int firstDigitBellow);
char *randomStringFloat(unsigned long long digits, unsigned long long DecDigits, unsigned int firstDigitAbove, unsigned int firstDigitBellow);
#endif


