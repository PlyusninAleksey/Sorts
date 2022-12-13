#include "ShakerSort.h"

void ShakerSort(int* array, int arrSize)
{
	int left = 1;
	int right = arrSize - 1;
	long long int countIf = 0;
	long long int countSwap = 0;
	while (left < right)
	{
		int i;
		for (i = left; i <= right; i++)
		{
			countIf++;
			if (array[i - 1] > array[i])
			{
				int temp;
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				countSwap++;
			}
		}
		right--;

		for (i = right; i >= left; i--)
		{
			countIf++;
			if (array[i] < array[i - 1])
			{
				int temp;
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				countSwap++;
			}
		}
		left++;
	}
	printf("CountIf = %lld\n", countIf);
	printf("CountSwap = %lld\n", countSwap);
}