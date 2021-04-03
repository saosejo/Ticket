/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Santiago Osejo
	ID     : 134962208
	Email  : sosejo-zuluaga@myseneca.ca
	Section: NEE
*/
#pragma once
#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

int currentYear(void);

void clearStandardInputBuffer(void);

int getPositiveInteger(void);

int getInteger(void);

int getIntFromRange(int min, int max);

double getDouble();

double getPositiveDouble(void);

char getCharOption(char* validChar);

void getCString(char* stringValue, int min, int max);


#endif // !COMMON_HELPERS_H_

