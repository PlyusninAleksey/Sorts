#include "SelectionSort.h"

void SelectionSort(int* array, int arrSize)
{
	int i, j;
	long long int countIf = 0;
	long long int countSwap = 0;
	for (i = 0; i < arrSize; i++)
	{
		int minIndex = i;
		for (j = i + 1; j < arrSize; j++)
		{
			countIf++;
			if (array[minIndex] > array[j])
			{
				minIndex = j;
			}
		}
		int temp = array[minIndex];
		array[minIndex] = array[i];
		array[i] = temp;
		countSwap++;
	}
	
	printf("CountIf = %lld\n", countIf);
	printf("CountSwap = %lld\n", countSwap);
}