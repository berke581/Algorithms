#include <stdio.h>
#include <stdlib.h>


#define SIZE 10
#define DIGIT_COUNT 10


void getInputs(int* arr);
void radixSort(int* arr, int* out_arr);
void hollerithSort(int* arr, int* out_arr);
void countingSort(int* arr, int digit);
void printArray(int* arr);
void countDifferences(int* radix_arr, int* hollerith_arr);


int main(void)
{
	int arr[SIZE] = {0};
	getInputs(arr);
	
	int radix_arr[SIZE] = {0};
	int hollerith_arr[SIZE] = {0};
	
	radixSort(arr, radix_arr);
	hollerithSort(arr, hollerith_arr);
	
	printArray(radix_arr);
	printArray(hollerith_arr);
	
	countDifferences(radix_arr, hollerith_arr);

	return 0;
}


void getInputs(int* arr)
{
	for (int i = 0; i < SIZE; ++i)
	{
		int element;
		scanf("%d", &element);
		arr[i] = element;
	}
}

void radixSort(int* arr, int* out_arr)
{
	for (int i = 0; i < SIZE; ++i)
		out_arr[i] = arr[i];
	
	int i = 1;
	while (i <= 100)
	{
		countingSort(out_arr, i);
		i *= 10;
	}
}

void hollerithSort(int* arr, int* out_arr)
{
	for (int i = 0; i < SIZE; ++i)
		out_arr[i] = arr[i];
	
	int i = 100;
	while (i >= 1)
	{
		countingSort(out_arr, i);
		i /= 10;
	}
}

void countingSort(int* arr, int digit)
{
	int countArr[DIGIT_COUNT] = {0};
	
	for (int i = 0; i < SIZE; ++i)
		++countArr[(arr[i] / digit) % 10];
	
	for (int i = 1; i < DIGIT_COUNT; ++i)
		countArr[i] += countArr[i - 1];
	
	int temp[SIZE];
	for (int i = SIZE - 1; i >= 0; --i)
		temp[--countArr[(arr[i] / digit) % 10]] = arr[i];
	
	for (int i = 0; i < SIZE; ++i)
		arr[i] = temp[i];
}

void printArray(int* arr)
{
	for (int i = 0; i < SIZE; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void countDifferences(int* radix_arr, int* hollerith_arr)
{
	int errCount = 0;
	
	for (int i = 0; i < SIZE; ++i)
		if (radix_arr[i] != hollerith_arr[i])
			++errCount;
	
	printf("%%%d hata\n", errCount * 10);
}

