#include "CountSort.h"


void CountSort(int* array, int arraySize)
{
	long long int countIf = 0;
	
	int MaxElement = array[0];
	for (int i = 0; i < arraySize; i++)
	{
		countIf++;
		if (MaxElement < array[i])
		{
			MaxElement = array[i];
		}
	}

	int MinElement = array[0];
	for (int i = 0; i < arraySize; i++)
	{
		countIf++;
		if (MinElement > array[i])
		{
			MinElement = array[i];
		}
	}

	int countSize;
	if (MinElement < 0)
	{
		countSize = MaxElement - MinElement + 1;
	}
	else
	{
		countSize = MaxElement + 1;
		MinElement = 0;
	}

	int* countArr = 0;
	countArr = (int*)malloc(countSize * sizeof(int));
	for (int i = 0; i < countSize; i++) { countArr[i] = 0; }


	for (int i = 0; i < arraySize; i++)
	{
		countArr[array[i] - MinElement] += 1;
	}
	int count = 0;
	for (int i = 0; i < countSize; i++)
	{
		for (int j = 0; j < countArr[i]; j++)
		{
			array[count] = i + MinElement;
			count++;
		}
	}
	free(countArr);

	printf("CountIf = %lld\n", countIf);
}