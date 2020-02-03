#include "randnums.h"

long int *randomIntegers(unsigned long long amount, long int min, long int max)
{
	long int *randomArray;

	randomArray = calloc( amount, sizeof(long int) );

	srand( time(NULL) );

	if(min > max)
		return NULL;
	for(unsigned long long index = 0; index < amount; index++)
	{
		if( min == max )
			randomArray[index] = (long int) max;
		else if( min <= 0 && max <= 0)// cases like -90 -5
			randomArray[index] = (long int) ( rand()%(min-max) )*-1 + max;
		else if(min >= 0 && max >= 0)// cases like 9 50
			randomArray[index] = (long int) rand()%(max-min)+min;
		else if( max >= 0 && min <= 0)// cases like -90 5
			randomArray[index] = (long int) ( rand()%(max-min) )*-1 + max;	
	}
	
	if(amount == 0)
		randomArray = NULL;

	return randomArray;	
}

long int randomInt(long int min, long int max)
{
	long int random = 0;

	srand (time(NULL));
	
	if(min > max)
		return 0;
	
	if( min == max )
		random = (long int) max;
	else if( min <= 0 && max <= 0)
		random = (long int) ( rand()%(min-max) )*-1 + max;
	else if(min >= 0 && max >= 0)
		random = (long int) rand()%(max-min)+min;
	else if( max >= 0 && min <= 0)
		random = (long int) ( rand()%(max-min) )*-1 + max;
		
	return random;	
}


long double *randomFloats(unsigned long long amount, long double min, long double max)
{
	long double *randomArray;
	long double scale;

	randomArray = calloc( amount, sizeof(long double) );

	srand (time(NULL));

	if(min > max)
		return NULL;

	for(unsigned long long index = 0; index < amount; index++)
	{
		scale = rand()/(long double) RAND_MAX;				
		if( min == max )
			randomArray[index] = (long double) max;
		else if( min <= 0 && max <= 0)
			randomArray[index] = (long double) ( min - scale*(min-max) );
		else if(min >= 0 && max >= 0)
			randomArray[index] = (long double) ( min - scale*(min-max) );
		else if( max >= 0 && min <= 0)
			randomArray[index] = (long double) ( min + scale*(max-min) );
	}
	
	if(amount == 0)
		randomArray = NULL;

	return randomArray;	
}


long double randomFloat(long double min, long double max)
{
	long double random = 0, scale;

	srand (time(NULL));

	if(min > max)
		return 0;

	scale = rand()/(long double) RAND_MAX;				
	if( min == max )
		random = (long double) max;
	else if( min <= 0 && max <= 0)
		random = (long double) ( min - scale*(min-max) );
	else if(min >= 0 && max >= 0)
		random = (long double) ( min - scale*(min-max) );
	else if( max >= 0 && min <= 0)
		random = (long double) ( min + scale*(max-min) );
	
	return random;	
}

char *randomStringInteger(unsigned long long digits, unsigned int firstDigitAbove, unsigned int firstDigitBellow)
{
	char *stringInteger;
	unsigned int digit = 0;

	stringInteger = calloc( digits + 1, sizeof(char) );	
	stringInteger[digits] = '\0';
	
	srand (time(NULL));
	
	if(firstDigitAbove > 9 || firstDigitAbove < 0 || firstDigitBellow < 0 || firstDigitBellow > 9)
		return "Error";
	if(firstDigitAbove > firstDigitBellow)
		return "Error";
	if(digits <= 0)
		return "Error";

	for(unsigned long long index = 0; index < digits; index++)
	{
		if( index == 0 )
			digit = rand()%(firstDigitBellow-firstDigitAbove) + firstDigitAbove;
		else
			digit = rand()%9;

		stringInteger[index] = digit + '0';
	}
	
	return stringInteger;
}

char *randomStringFloat(unsigned long long digits, unsigned long long DecDigits, unsigned int firstDigitAbove, unsigned int firstDigitBellow)
{
	char *stringFloat;
	unsigned int digit = 0;

	stringFloat = calloc( digits + DecDigits + 2, sizeof(char) ); // +1 for the '.' character	
	stringFloat[digits + DecDigits + 1] = '\0';
	
	srand (time(NULL));
	
	if(firstDigitAbove > 9 || firstDigitAbove < 0 || firstDigitBellow < 0 || firstDigitBellow > 9)
		return "Error";
	if(firstDigitAbove > firstDigitBellow)
		return "Error";
	if(digits <= 0)
		return "Error";

	for(unsigned long long index = 0; index < digits; index++)
	{
		if( index == 0 )
			digit = rand()%(firstDigitBellow-firstDigitAbove) + firstDigitAbove;
		else
			digit = rand()%9;

		stringFloat[index] = digit + '0';
	}
	stringFloat[digits] = '.';
	
	for(unsigned long long index = digits+1 ; index < digits + DecDigits + 1; index++)
	{
		if( index == 0 )
			digit = rand()%firstDigitBellow + (firstDigitBellow-firstDigitAbove);
		else
			digit = rand()%9;
		 
		stringFloat[index] = digit + '0';
	}
	
	return stringFloat;
}


