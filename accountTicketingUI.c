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

void displayAccountSummaryHeader(void) {
	printf("Acct#  Acct.Type Birth\n");
	printf("------ --------- -----\n");
}

void displayAccountDetailHeader(void) {
	printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
}

void displayAccountSummaryRecord(struct Account account, struct Demographic demo) {
	printf("%06d %-9s %5d\n", account.accountNumber, (account.accountType == 'A' ? "AGENT" : "CUSTOMER"), demo.customerBirthYear);
}

void displayAccountDetailRecord(struct Account account, struct Demographic demo, struct UserLogin login) {
	int i;
	for ( i = 0; i < 8; i++)
	{
		if (i%2==1)
		{
			login.userPassword[i] = '*';
		}
	}
	printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s\n", account.accountNumber, (account.accountType == 'A' ? "AGENT" : "CUSTOMER"), demo.customerBirthYear, demo.houseHoldIncome, demo.customerCountry, login.accountHolder, login.userLogin, login.userPassword);
}

// Pause execution until user enters the enter key
void pauseExecution(void)
{
	printf("<< ENTER key to Continue... >>");
	clearStandardInputBuffer();
	getchar();
	printf("\n");
}

void pauseExecution1(void)
{
	printf("<< ENTER key to Continue... >>");
	getchar();
	printf("\n");
}

int findAccountIndexByAcctNum(int index, struct Account account[], int size, int prompt) {
	int accountNumber, i;
	if (prompt == 1)
	{
		printf("Enter your account#: ");
		scanf("%d", &accountNumber);
		printf("\n");
		
	}
	else
	{
		accountNumber = index;
	}
	for (i = 0; i < size; i++)
	{
		if (accountNumber == account[i].accountNumber)
		{
			return i;
		}
	}

	return -1;
}

int findAccountIndexByAcctNum1(int index, struct Account account[], int size, int prompt) {
	int accountNumber, i;
	if (prompt == 1)
	{
		printf("Enter the account#: ");
		scanf("%d", &accountNumber);
		printf("\n");

	}
	else
	{
		accountNumber = index;
	}
	for (i = 0; i < size; i++)
	{
		if (accountNumber == account[i].accountNumber)
		{
			return i;
		}
	}

	return -1;
}

int findAccountIndexByAcctNum2(int index, struct Account account[], int size, int prompt) {
	int accountNumber, i;
	if (prompt == 1)
	{
		printf("Enter the account#: ");
		scanf("%d", &accountNumber);

	}
	else
	{
		accountNumber = index;
	}
	for (i = 0; i < size; i++)
	{
		if (accountNumber == account[i].accountNumber)
		{
			return i;
		}
	}

	return -1;
}

void displayAllAccountSummaryRecords(struct Account account[], int size) {
	int i;
	printf("\n");
	displayAccountSummaryHeader();
	for ( i = 0; i < size; i++)
	{
		if (account[i].accountNumber>0)
		{
			
			displayAccountSummaryRecord(account[i], account[i].demo);
		}
	}
	printf("\n");
}

void displayAllAccountDetailRecords(struct Account account[], int size) {
	int i;
	
	displayAccountDetailHeader();
	for (i = 0; i < size; i++)
	{
		if (account[i].accountNumber > 0)
		{
		
			displayAccountDetailRecord(account[i], account[i].demo, account[i].login);
		}
	}
	printf("\n");
}


int menuLogin(struct Account account[], int size) {
	int selection, accountNumber=0,valid=1;
	char getCharacter;
	do
	{
		
		printf("==============================================\n");
		printf("Account Ticketing System - Login\n");
		printf("==============================================\n");
		printf("1) Login to the system\n");
		printf("0) Exit application\n");
		printf("----------------------------------------------\n");
		printf("\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 1);
		valid = 1;
		if (selection == 1)
		{
			printf("\n");
			accountNumber = findAccountIndexByAcctNum(account->accountNumber, account, size, 1);
			
			valid = 1;
			if (accountNumber < 0)
			{
				printf("ERROR:  Access Denied.\n");
				printf("\n");
				pauseExecution();
				
				
			}
			else
			{
				return accountNumber;
			}
			
		}
		if (selection == 0)
		{
			printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
			getCharacter = getCharOption("yYnN");
			printf("\n");
			if (getCharacter == 'y' || getCharacter == 'Y')
			{
				valid = 0;
			}
		}
	} while (valid);
	
	
	return -1;
}

void menuAgent(struct Account account[], int size, int index) {

	int selection, token=0, accountNumber, accountNumberActual,valid=1, accounHolder;
	char charValue;
	accounHolder= account[index].accountNumber;
	do
	{
		
		printf("AGENT: %s (%d)\n", account[index].login.accountHolder, accounHolder);
		printf("==============================================\n");
		printf("Account Ticketing System - Agent Menu\n");
		printf("==============================================\n");
		printf("1) Add a new account\n");
		printf("2) Modify an existing account\n");
		printf("3) Remove an account\n");
		printf("4) List accounts: summary view\n");
		printf("5) List accounts: detailed view\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n");
		printf("\n");
		printf("Selection: ");
		selection = getIntFromRange(0, 5);
		if (selection == 1)
		{
			accountNumber = findAccountIndexByAcctNum(0, account, size, 0);
			if (accountNumber >= 0) {
				getAccount(&account[accountNumber]);
				getUserLogin(&account[accountNumber].login);
				getDemographic(&account[accountNumber].demo);
				printf("*** New account added! ***\n");
				printf("\n");
				pauseExecution();
				token = 1;
			}
			if (token == 0)
			{
				printf("ERROR: Account listing is FULL, call ITS Support!\n");
			}
		}
		if (selection == 2)
		{
			token = 0;
			printf("\n");
			accountNumber = findAccountIndexByAcctNum1(account->accountNumber, account, size, 1);
		
			updateAccount(&account[accountNumber]);

			
			token = 1;

			if (token == 0)
			{
				printf("ERROR: Account listing is FULL, call ITS Support!\n");
			}
		}
		if (selection == 3)
		{
			token = 0;
			printf("\n");
			accountNumber = findAccountIndexByAcctNum2(account->accountNumber, account, size, 1);
			accountNumberActual = findAccountIndexByAcctNum2(account[index].accountNumber, account, size, 0);
			if (accountNumber >= 0 && accountNumber != accountNumberActual)
			{
				displayAllAccountDetailRecords(&account[accountNumber], 1);
				clearStandardInputBuffer();
				printf("Are you sure you want to remove this record? ([Y]es|[N]o): ");
				charValue = getCharOption("YN");
				if (charValue == 'Y')
				{
					account[accountNumber].accountNumber = 0;
					token = 1;
					printf("\n");
					printf("*** Account Removed! ***\n");
					printf("\n");
					pauseExecution1();
				}

				}
			else if (accountNumber >= 0 && accountNumber == accountNumberActual)
			{
				printf("\n");
				printf("ERROR: You can't remove your own account!\n");
				token = 1;
				printf("\n");
				pauseExecution();
				
			}
			
			if (token == 0)
			{
				printf("\n");
				printf("*** No changes made! ***\n");
				printf("\n");
				pauseExecution1();
			}
		}
		if (selection == 4)
		{
			
			displayAllAccountSummaryRecords(account, size);
			pauseExecution1();
		}
		if (selection == 5)
		{
			printf("\n");
			displayAllAccountDetailRecords(account, size);
			pauseExecution1();
		}
		if (selection == 0)
		{
			printf("\n### LOGGED OUT ###\n");
			printf("\n");
			valid = 0;
		}

	} while (valid);

}

void applicationStartup(struct Account account[],int size) {
	int index, valid=1;
	
	while (valid)
	{

		index = menuLogin(account, size);
	
		if (index >= 0)
		{
			if (account[index].accountType == 'A') {
				menuAgent(account, size, index);

			}
			else
			{
				printf("CUSTOMER: home menu currently unavailable...\n");
				printf("\n");
				pauseExecution();
				
			}
		}
		else
		{
			printf("==============================================\n");
			printf("Account Ticketing System - Terminated\n");
			printf("==============================================\n");
			valid = 0;
		}
	}
}