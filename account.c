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
#include "account.h"
#include "accountTicketingUI.h"

void getAccount(struct Account* account) {

	printf("\n");
	printf("Account Data: New Record\n");
	printf("----------------------------------------\n");
	printf("Enter the account number: ");
	account->accountNumber = getInteger();
	printf("\n");
	printf("Enter the account type (A=Agent | C=Customer): ");
	account->accountType = getCharOption("AC");
	printf("\n");

}


void getUserLogin(struct UserLogin* login) {
	
	printf("User Login Data Input\n");                 // *** DO NOT MODIFY THIS LINE ***
	printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***
	printf("Enter user login (%d chars max): ", MAX_LOGIN);
	getCString(login->userLogin, 1, MAX_LOGIN);
	printf("Enter the display name (%d chars max): ", MAX_HOLDER);
	getCString(login->accountHolder, 0, MAX_HOLDER);
	printf("Enter the password (must be %d chars in length): ", MAX_PASSWORD);
	getCString(login->userPassword, MAX_PASSWORD, MAX_PASSWORD);
	printf("\n");

}

void getDemographic(struct Demographic* demographic) {

	printf("Demographic Data Input\n");                // *** DO NOT MODIFY THIS LINE ***
	printf("----------------------------------------\n"); // *** DO NOT MODIFY THIS LINE ***
	printf("Enter birth year (current age must be between 18 and 110): ");
	demographic->customerBirthYear = getIntFromRange((currentYear() - 110), (currentYear() - 18));
	printf("Enter the household Income: $");
	demographic->houseHoldIncome = getPositiveDouble();
	printf("Enter the country (%d chars max.): ", MAX_COUNTRY);
	getCString(demographic->customerCountry, 0, MAX_COUNTRY);
	printf("\n");

}

void updateAccount(struct Account* account) {
	int selection,valid=1;
	do
	{

		printf("Account: %5d - Update Options\n", account->accountNumber);
		printf("----------------------------------------\n");
		printf("1) Update account type (current value: %c)\n", account->accountType);
		printf("2) Login\n");
		printf("3) Demographics\n");
		printf("0) Done\n");
		printf("Selection: ");

		selection = getIntFromRange(0, 3);
		if (selection == 1)
		{
			printf("\n");
			printf("Enter the account type (A=Agent | C=Customer): ");
			account->accountType = getCharOption("AC");
			printf("\n");

		}
		else if (selection == 2)
		{
			
			updateUserLogin(account);

		}
		else if (selection == 3)
		{
			updateDemographic(account);
		}
		else if (selection == 0)
		{
			valid = 0;
			printf("\n");
		}
	} while (valid);
	
}

void updateUserLogin(struct Account* account) {
	int selection, valid = 1;
	
	do
	{
		printf("\n");
		printf("User Login: %s - Update Options\n", account->login.userLogin);
		printf("----------------------------------------\n");
		printf("1) Display name (current value: %s)\n", account->login.accountHolder);
		printf("2) Password\n");
		printf("0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 3);
		if (selection == 1)
		{
			printf("\n");
			printf("Enter the display name (30 chars max): ");
			getCString(account->login.accountHolder, 0, MAX_HOLDER);
			
		}
		else if (selection == 2)
		{
			printf("\n");
			printf("Enter the password (must be 8 chars in length): ");
			getCString(account->login.userPassword, MAX_PASSWORD, MAX_PASSWORD);
			
		}
		else if (selection == 0)
		{
			valid = 0;
			printf("\n");
		
		}
	} while (valid);
}

void updateDemographic(struct Account* account) {
	int selection, valid = 1;
	do
	{
		printf("\n");
		printf("Demographic Update Options\n");
		printf("----------------------------------------\n");
		printf("1) Household Income (current value: $%.2lf)\n", account->demo.houseHoldIncome);
		printf("2) Country (current value: %s)\n",account->demo.customerCountry);
		printf("0) Done\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 3);
		if (selection == 1)
		{
			printf("\n");
			printf("Enter the household Income: $");
			account->demo.houseHoldIncome = getPositiveDouble();
			
		}
		else if (selection == 2)
		{
			printf("\n");
			printf("Enter the country (30 chars max.): ");
			getCString(account->demo.customerCountry, 0, MAX_COUNTRY);
			
		}
		else if (selection == 0)
		{
			valid = 0;
			printf("\n");
		}
	} while (valid);
}



