/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Santiago Osejo
	ID     : 134962208
	Email  : sosejo-zuluaga@myseneca.ca
	Section: NEE
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "commonHelpers.h"

// Uses the time.hlibrary to obtain current year information
// Get the current 4-digit yearfrom the system
int currentYear(void) {
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}

// Empty the standard input buffer
void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing
	}
}

int getInteger(void)
{
	int valid = 1, value;
	char newLine = 'x';
	do
	{
		scanf("%d%c", &value, &newLine);
		if (newLine == '\n')
		{
			valid = 0;
			return value;
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	} while (valid);
	return 0;
}

int getPositiveInteger(void)
{
	int valid = 1, value;
	char newLine = 'x';
	do
	{
		scanf("%d%c", &value, &newLine);
		if (newLine == '\n' && value > 0)
		{
			valid = 0;
			return value;
		}
		else
		{
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
	} while (valid);
	return 0;
}

double getDouble()
{
	int valid = 1;
	double value = 0.0;
	char newLine = 'x';
	do
	{
		scanf("%lf%c", &value, &newLine);
		if (newLine == '\n')
		{
			valid = 0;
			return value;
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}

	} while (valid);
	return 0;
}

double getPositiveDouble(void)
{
	int valid = 1;
	double value = 0.0;
	char newLine = 'x';
	do
	{
		scanf("%lf%c", &value, &newLine);
		if (newLine == '\n')
		{
			if (value > 0)
			{
				valid = 0;
				return value;
			}
			printf("ERROR: Value must be a positive double floating-point number: ");
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (valid);
	return 0;
}

int getIntFromRange(int min, int max)
{
	int valid = 1;
	do
	{
		int value;
		char newLine = 'x';
		scanf("%d%c", &value, &newLine);
		if (newLine == '\n')
		{
			if (value <= max && value >= min)
			{
				valid = 0;
				return value;
			}
			else
			{
				printf("ERROR: Value must be between %d and %d inclusive: ", min, max);
				
			}
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
			
		}
	} while (valid);
	return 0;
}

char getCharOption(char* validChar)
{
	char value = 'x', newLine = 'x';
	int i, valid = 1;
	do
	{
		scanf("%c%c", &value, &newLine);
		if (newLine == '\n') {
			for (i = 0; validChar[i] != '\0'; i++)
			{
				if (value == validChar[i])
				{
					valid = 0;
					return value;
				}
			}
			printf("ERROR: Character must be one of [%s]: ", validChar);
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Character must be one of [%s]: ", validChar);
		}


	} while (valid);
	return 0;
}

void getCString(char* stringValue, int min, int max)
{
	int i, valid = 1, j;
	char line[30];

	do
	{
		scanf(" %[^\n]s", line);
		i = 0;
		while (line[i] != '\0')
			i++;

		if (i >= min && i <= max)
		{
			j = 0;
			while (line[j] != '\0')
			{
				stringValue[j] = line[j];
				j++;
			}
			stringValue[j] = '\0';

			//strcpy(stringValue, line);
			valid = 0;
		}
		else
		{
			if (min == max)
			{
				clearStandardInputBuffer();
				printf("ERROR: String length must be exactly %d chars: ", min);
			}
			else
			{
				if (i > max)
				{
					clearStandardInputBuffer();
					printf("ERROR: String length must be no more than %d chars: ", max);
				}
				if (i < max)
				{
					clearStandardInputBuffer();
					printf("ERROR: String length must be between %d and %d chars: ", min, max);
				}
			}
		}
	} while (valid);
}
