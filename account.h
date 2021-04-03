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
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#define MAX_COUNTRY 30
#define MAX_HOLDER 30
#define MAX_LOGIN 10
#define MAX_PASSWORD 8

struct Demographic
{
	int customerBirthYear;
	double houseHoldIncome;
	char customerCountry[MAX_COUNTRY];
};

struct UserLogin
{
	char accountHolder[MAX_HOLDER];
	char userLogin[MAX_LOGIN + 1];
	char userPassword[MAX_PASSWORD + 1];
};

struct Account
{
	int accountNumber;
	char accountType;
	struct UserLogin login;
	struct Demographic demo;
};

void getAccount(struct Account* account);

void getDemographic(struct Demographic* demographic);

void getUserLogin(struct UserLogin* login);

void updateAccount(struct Account* account);

void updateDemographic(struct Account* account);

void updateUserLogin(struct Account* account);

#endif // !ACCOUNT_H_

