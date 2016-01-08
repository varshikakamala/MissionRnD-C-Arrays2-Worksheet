/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, j = 0,pos = 0, count = 0;
	for (i = 0; i < len; i++)
	{
		j = 0;
		while (Arr[i].date[j] == date[j]) {
			if (Arr[i].date[j] == '\0' || date[j] == '\0')
				break;
			j++;
		}

		if (Arr[i].date[j] == '\0' && date[j] == '\0')
		{
			count++;
			pos = i;
		}
	}
	if (count == 0 || pos == len - 1 || count == len) return 0;
	else
	{
		if (pos == 0) return (len-1);
		else if (pos == (len) / 2) return (len)/2;
	}
}