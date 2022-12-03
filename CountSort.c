#include "CountSort.h"

int maxElement(int* array, int arraySize)
{
	int max = array[0];
	for (int i = 0; i < arraySize; i++)
	{
		if (max < array[i])
		{
			max = array[i];
		}
	}
	return max;
}

int minElement(int* array, int arraySize)
{
	int min = array[0];
	for (int i = 0; i < arraySize; i++)
	{
		if (min > array[i])
		{
			min = array[i];
		}
	}
	return min;
}

void CountSort(int* array, int arraySize)
{
	
	int MaxElement = maxElement(array, arraySize);
	int MinElement = minElement(array, arraySize);

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
}