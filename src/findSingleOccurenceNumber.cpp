/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) {
	if (len<=2) return -1;
	else
	{
		int i,j,single_number = 0, sum=0,n;
		for (i = 0; i < 4; i++)
		{
			sum = 0;
			n = (1 << i);
			for (j = 0; j < len; j++)
			{
				if (A[j] & n)
					sum++;
			}
			if (sum % 3)
				single_number=single_number|n;
		}
		return single_number;
	}
}