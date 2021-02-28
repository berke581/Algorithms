#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int* arr = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; ++i)
	{
		int element;
		scanf("%d", &element);
		arr[i] = element;
	}
	
	int* prev = (int*)malloc(sizeof(int) * n);
	int* post = (int*)malloc(sizeof(int) * n);
	
	int product = 1;
	for (int i = 0; i < n; ++i)
	{
		prev[i] = product;
		product *= arr[i];
	}
	
	product = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		post[i] = product;
		product *= arr[i];
	}
	
	for (int i = 0; i < n; ++i)
		printf("%d ", prev[i] * post[i]);
	
	printf("\n");
	
	free(arr);
	free(prev);
	free(post);
	
	return 0;
}

