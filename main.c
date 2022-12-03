#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "CountSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "LinearSearch.h"
#include "BinarySearch.h"


void main()
{
	int i;
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(NULL));

	int ARRAY_LENGTH;
	printf("������� ������ �������: ");
	scanf_s("%i", &ARRAY_LENGTH);

	int* array = (int*)malloc(ARRAY_LENGTH * sizeof(int));

	printf("������� �������� �������� ������� [a;b]\n");
	int a, b;
	printf("a = ");
	scanf_s("%i", &a);
	printf("b = ");
	scanf_s("%i", &b);

	for (i = 0; i < ARRAY_LENGTH; i++)
	{
		array[i] = (rand() % (b - a + 1)) + a;
	}

	int flag;
	printf("�������� ������? ���� �� �������, �� ������� 1, ����� ������� 0: ");
	scanf_s("%i", &flag);

	if (flag)
	{
		printf("�������� ������:\n");
		for (i = 0; i < ARRAY_LENGTH; i++)
		{
			printf("%d ", array[i]);
		}
	}

	printf("\n���� ����������:\n");
	int n;
	printf("1.����������� ����������.\n");
	printf("2.���������� �������.\n");
	printf("3.���������� ���������.\n");
	printf("4.���������� ���������.\n");
	printf("5.������� ����������.\n");
	printf("6.���������� ��������.\n");

	printf("�������� ��� ����������:");
	scanf_s("%d", &n);
	clock_t time;
	switch (n)
	{
	case 1:
		time = clock();
		BubbleSort(array, ARRAY_LENGTH);
		time = clock() - time;
		printf("Time = %lf\n", (double)time / CLOCKS_PER_SEC);
		break;
	case 2:
		time = clock();
		SelectionSort(array, ARRAY_LENGTH);
		time = clock() - time;
		printf("Time = %lf\n", (double)time / CLOCKS_PER_SEC);
		break;
	case 3:
		time = clock();
		InsertionSort(array, ARRAY_LENGTH);
		time = clock() - time;
		printf("Time = %lf\n", (double)time / CLOCKS_PER_SEC);
		break;
	case 4:
		time = clock();
		CountSort(array, ARRAY_LENGTH);
		time = clock() - time;
		printf("Time = %lf\n", (double)time / CLOCKS_PER_SEC);
		break;
	case 5:
		time = clock();
		QuickSort(array, 0, ARRAY_LENGTH - 1);
		time = clock() - time;
		printf("Time = %lf\n", (double)time / CLOCKS_PER_SEC);
		break;
	case 6:
	{
		time = clock();
		int*buffer = (int*)malloc(ARRAY_LENGTH * sizeof(int));
		MergeSort(array, buffer, 0, ARRAY_LENGTH - 1);
		time = clock() - time;
		printf("Time = %lf\n", (double)time / CLOCKS_PER_SEC);
		free(buffer);
		break;
	}
	default:
		printf("������� ����� �����");
		break;
	}
	

	//BubbleSort(array, ARRAY_LENGTH);
	//SelectionSort(array, ARRAY_LENGTH);
	//InsertionSort(array, ARRAY_LENGTH);
	//CountSort(array, ARRAY_LENGTH);
	//QuickSort(array, 0 , ARRAY_LENGTH - 1);

	if (flag)
	{
		printf("\n���������������� ������:\n");
		for (i = 0; i < ARRAY_LENGTH; i++)
		{
			printf("%d ", array[i]);
		}
	}

	printf("\n����� �������� � �������, ������� ��������:");
	int key;
	scanf_s("%d", &key);
	printf("���� ������:\n");
	printf("1.�������� �����.\n");
	printf("2.�������� �����.\n");
	printf("�������� ��� ������:");
	scanf_s("%d", &n);

	int searchIndex = -1;
	switch(n)
	{
	case 1:
		time = clock();
		searchIndex = LinearSearch(array, ARRAY_LENGTH, key);
		time = clock() - time;
		printf("Time = %lf\n", (double)time / CLOCKS_PER_SEC);
		break;
	case 2:
		time = clock();
		searchIndex = BinarySearch(array, ARRAY_LENGTH, key);
		time = clock() - time;
		printf("Time = %lf\n", (double)time / CLOCKS_PER_SEC);
		break;
	default:
		printf("������� ����� �����.\n");
		searchIndex = -1;
		break;
	}

	if (searchIndex != -1)
	{
		printf("a[%d] = %d", searchIndex, array[searchIndex]);
	}
	else
	{
		printf("������� ������� �� ������");
	}
	free(array);
}