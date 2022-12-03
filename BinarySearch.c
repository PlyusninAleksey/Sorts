#include "BinarySearch.h"

int BinarySearch(int* array, int arrSize, int key)
{
	int left = 0;
	int mid;
	int right = arrSize - 1;
	int flag = 0;
	
	while ((left <= right) && (flag != 1))
	{
		mid = (left + right) / 2;
		if (array[mid] == key) { flag = 1; }
		if (array[mid] < key) { left = mid + 1; }
		if (array[mid] > key) { right = mid - 1; }
	}
	

	if (flag == 0)
	{
		return -1;
	}
	else
	{
		return mid;
	}
}
