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
#ifndef ACCOUNT_TICKETING_H_
#define ACCOUNT_TICKETING_H_

void displayAccountSummaryHeader(void);

void displayAccountDetailHeader(void);

void displayAccountSummaryRecord(struct Account account, struct Demographic demo);

void displayAccountDetailRecord(struct Account account, struct Demographic demo, struct UserLogin login);

int findAccountIndexByAcctNum(int index, struct Account account[], int size, int prompt);

void applicationStartup(struct Account account[], int size);

void pauseExecution(void);

void pauseExecution1(void);

#endif // !ACCOUNT_TICKETING_H_