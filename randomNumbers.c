#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
/*

Six powerfull functions to get random numbers, see the menu() function bellow to learn how to use each of them...

-A / randomIntegers -> returns an array of random integers according to the parameters passed.
-a / randomFloats -> returns an array of random floats according to the parameters passed.
-i / randomInt -> returns a random integer according to the parameters passed.
-f / randomFloat -> returns a random float according to the parameters passed.
-S / randomStringInteger -> returns a random integer (as a string) made out of individual random digits according to the parameters passed.
-s / randomStringInteger -> returns a random float (as a string) made out of individual random digits according to the parameters passed.

*/
long int *randomIntegers(unsigned long long amount, long int min, long int max);
long double *randomFloats(unsigned long long amount, long double min, long double max);
long int randomInt(long int min, long int max);
long double randomFloat(long double min, long double max);
char *randomStringInteger(unsigned long long digits, unsigned int firstDigitAbove, unsigned int firstDigitBellow);
char *randomStringFloat(unsigned long long digits, unsigned long long DecDigits, unsigned int firstDigitAbove, unsigned int firstDigitBellow);
void menu(char *argv[]);

int main(int argc, char * argv[])
{	
	menu(argv);
	return EXIT_SUCCESS;
}

void menu(char *argv[])
{
	char opc[1], *randomStr;
	opc[0] = argv[1][1];
	long int *randomArray, randomI;
	long double *randomDoubles, randomF;

	switch(opc[0])
	{
		case 'A':// -A [amount_of_random_integers] [maximum_value_for_each_integer] [minimum_value_for_each_integer] (e.g. -A 10 35 80)
			
			randomArray = randomIntegers( atoi( argv[2] ), atoi( argv[3] ), atoi( argv[4] ) );
			for(unsigned long long index = 0; index < atoi( argv[2] ); index++)
				printf("%li,", randomArray[index]);
			//...
			free(randomArray);
		break;

		case 'a':// -a [amount_of_random_floats] [maximum_value_for_each_float] [minimum_value_for_each_float] (e.g. -a 10 -35.77 35.96)
		
			randomDoubles = randomFloats( atoi( argv[2] ), atoi( argv[3] ), atoi( argv[4] ) );
			for(unsigned long long index = 0; index < atoi( argv[2] ); index++)
				printf("%LG,", randomDoubles[index]);
			//...
			free(randomDoubles);

		break;

		case 'i':// -i [maximum_value_for_each_integer] [minimum_value_for_each_integer] (e.g. -i -35 -5)
			randomI = randomInt( atoi( argv[2] ), atoi( argv[3] ) );
			printf("%li\n", randomI);
		break;
		
		case 'f':// -f [maximum_value_for_each_float] [minimum_value_for_each_float] (e.g. -f -35.87 -5.87)
			randomF = randomFloat( atoi( argv[2] ), atoi( argv[3] ) );
			printf("%LG\n", randomF);
		break;

		case 'S':// -S [amount_of_digits] [maximum_value_for_first_digit] [minimum_value_for_first_digit] (e.g. -S 35 5 9)
			randomStr = randomStringInteger( atoi( argv[2] ), atoi( argv[3] ), atoi( argv[4] ) );
			printf("%s\n", randomStr);
		break;

		case 's':/* -s [amount_of_digits_you_want_for_whole_part] [amount_of_digits_you_want_for_decimal_part]  [maximum_value_for_first_digit] [minimum_value_for_first_digit] (e.g. -s 50 50 3 8)*/
			randomStr = randomStringFloat( atoi( argv[2] ), atoi( argv[3] ), atoi( argv[4] ), atoi( argv[5] ) );
			printf("%s\n", randomStr);
		break;

	};
	return;
	
}

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


