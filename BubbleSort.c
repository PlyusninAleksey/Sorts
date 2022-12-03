#include "BubbleSort.h"


void BubbleSort(int* array, int arrSize)
{
	long long int countIf = 0;
	long long int countSwap = 0;

	int i, j;
	
	for (i = 0; i < arrSize; i++)
	{
		for (j = 1; j < arrSize - i; j++)
		{
			countIf++;
			if (array[j] < array[j - 1])
			{
				int temp;
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				
				countSwap++;
			}
		}
	}
	printf("CountIf = %lld\n", countIf);
	printf("CountSwap = %lld\n", countSwap);
}