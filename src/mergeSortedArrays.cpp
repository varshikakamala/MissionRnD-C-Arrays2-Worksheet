/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
if(A==NULL || B==NULL)	return NULL;
else
{
	struct transaction *Answer;
	int ALen = 3, BLen = 3;
	Answer = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	int i = 0, j = 0, k = 0, m = 0;
	while (i < ALen && j < BLen)
	{
		if (A[i].amount < B[j].amount)
		{
			Answer[k].amount = A[i].amount;
			while (A[i].date[m] != '\0')
			{
				Answer[k].date[m] = A[i].date[m];
				m++;
			}
			m = 0;
			while (A[i].description[m] != '\0')
			{
				Answer[k].description[m] = A[i].description[m];
				m++;
			}
			i++;
		}
		else
		{
			Answer[k].amount = B[j].amount;
			while (A[j].date[m] != '\0')
			{
				Answer[k].date[m] = B[j].date[m];
				m++;
			}
			m = 0;
			while (A[j].description[m] != '\0')
			{
				Answer[k].description[m] = B[j].description[m];
				m++;
			}
			j++;
		}
		k++;
	}
	if (i >= ALen)
	{
		m = 0;
		while (j < BLen)
		{
			Answer[k].amount = B[j].amount;
			while (A[j].date[m] != '\0')
			{
				Answer[k].date[m] = B[j].date[m];
				m++;
			}
			m = 0;
			while (A[j].description[m] != '\0')
			{
				Answer[k].description[m] = B[j].description[m];
				m++;
			}
			j++;
			k++;
		}
	}
	if (j >= BLen)
	{
		m = 0;
		while (i < ALen)
		{
			Answer[k].amount = A[i].amount;
			while (A[i].date[m] != '\0')
			{
				Answer[k].date[m] = A[i].date[m];
				m++;
			}
			m = 0;
			while (A[i].description[m] != '\0')
			{
				Answer[k].description[m] = A[i].description[m];
				m++;
			}
			i++;
			k++;
		}
	}
	return Answer;
}

}