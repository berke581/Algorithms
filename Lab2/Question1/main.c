#include <stdio.h>
#include <stdlib.h>

// function that flips bool values
int flipValue(int x);

// function that allocates enough room on the heap, initializes it to all zeros and returns the address
int* allocateArray(size_t arraySize);

// function that deletes the array
void deleteArray(int* arr);

// function that checks and modifies the array
void checkArray(int* arr, size_t arraySize);

// function that prints elements of the array that are one
void printArray(int* arr, size_t arraySize);

int main() {
    size_t input;
    scanf("%zu", &input);

    int* arr = allocateArray(input);

    checkArray(arr, input);
    printArray(arr, input);
    deleteArray(arr);

    return 0;
}

int flipValue(int x)
{
    if (x == 1)
        return 0;
    else if (x == 0)
        return 1;

    return x;
}

int* allocateArray(size_t arraySize)
{
    int* temp = (int*)malloc(sizeof(int) * arraySize);

    for (int i = 0; i < arraySize; ++i)
        temp[i] = 0;

    return temp;
}

void deleteArray(int* arr)
{
    free(arr);
}

void checkArray(int* arr, size_t arraySize)
{
    for (int i = 0; i < arraySize; ++i)
        for (int j = i; j < arraySize; j += i + 1)
            arr[j] = flipValue(arr[j]);
}

void printArray(int* arr, size_t arraySize)
{
    for (int i = 0; i < arraySize; ++i)
        if (arr[i] == 1)
            printf("%d ", i + 1);
}
