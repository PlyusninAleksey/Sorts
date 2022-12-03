#include "LinearSearch.h"
int LinearSearch(int* array, int arrSize, int key)
{
	int i = 0;
	int flag = 0;
	while (i < arrSize && flag != 1)
	{
		if (array[i] == key) { flag = 1; }
		i++;
	}
	
	if (flag == 0)
	{
		return -1;
	}
	else
	{
		return (i - 1);
	}
}