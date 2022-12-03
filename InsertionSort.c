	#include "InsertionSort.h"

void InsertionSort(int* array, int arrSize)
{
	int i, j;
	long long int countSwap = 0;
	for (i = 1; i < arrSize; i++)
	{
		j = i - 1;
		int newElement = array[i];
		while ((j >= 0) && array[j] > newElement)
		{
			array[j + 1] = array[j];
			array[j] = newElement;
			countSwap++;
			j--;
		}
	}
	printf("CountSwap = %lld\n", countSwap);
}