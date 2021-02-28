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
	
	for (int i = 0; i < n; ++i)
	{
		int product = 1;
		
		for (int j = 0; j < n; ++j)
		{
			if (j != i)
				product *= arr[j];
		}
		
		printf("%d ", product);
	}
	
	printf("\n");
	
	free(arr);
	
	return 0;
}

