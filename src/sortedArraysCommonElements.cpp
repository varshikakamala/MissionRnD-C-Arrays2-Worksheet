/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *Answer;
	Answer =(struct transaction*)malloc(ALen*sizeof(struct transaction));
	int i,k, j = 0, pos = 0, count = 0,m=0;
	if (A == NULL || B == NULL) return NULL;
	for (i = 0; i < ALen; i++)
	{
		
		for (k = 0; k < BLen; k++)
		{
			j = 0;
			while (A[i].date[j] == B[k].date[j])
			{
				if (A[i].date[j] == '\0' || B[k].date[j] == '\0')
					break;
				j++;
			}

			if (A[i].date[j] == '\0' && B[k].date[j] == '\0')
			{
				Answer[count].amount = A[i].amount;
				while (A[i].date[m] != '\0')
				{
					Answer[count].date[m] = A[i].date[m];
					m++;
				}
				m = 0;
				while (A[i].description[m] != '\0')
				{
					Answer[count].description[m] = A[i].description[m];
					m++;
				}
				count++;
				pos = i;
			}
		}
	}
	if (count == 0) return NULL;
	else if (count == ALen) return A;
	else return Answer;
 }