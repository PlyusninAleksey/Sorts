#include "QuickSort.h"

void QuickSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int mid = arr[(i + j) / 2];
	while (i <= j) {
		while (arr[i] < mid) {
			i++;
		}
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			int temp;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	if (j > left) {
		QuickSort(arr, left, j);
	}
	if (i < right) {
		QuickSort(arr, i, right);
	}
}