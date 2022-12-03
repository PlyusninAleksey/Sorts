#include "MergeSort.h"

void Merge(int* arr, int* buffer, int left, int mid, int right) {
	int pos = 0;
	int i = left, j = mid + 1;
	while ((i <= mid) && (j <= right))
	{
		if (arr[i] < arr[j]) {
			buffer[pos] = arr[i];
			i++;
		}
		else
		{
			buffer[pos] = arr[j];
			j++;
		}
		pos++;
	}
	while (i <= mid) {
		buffer[pos] = arr[i];
		pos++;
		i++;
	}
	while (j <= right) {
		buffer[pos] = arr[j];
		pos++;
		j++;
	}
	for (i = 0; i < pos; i++) {
		arr[left + i] = buffer[i];
	}
}
void MergeSort(int arr[], int buffer[], int left, int right) {
	if (right - left <= 1)
	{
		if (arr[left] > arr[right]) {
			int temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
		}
		return;
	}
	int mid = (left + right) / 2;

	MergeSort(arr, buffer, left, mid);
	MergeSort(arr, buffer, mid + 1, right);
	Merge(arr, buffer, left, mid, right);
}