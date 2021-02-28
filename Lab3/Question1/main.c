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
	
	for (int i = 0; i < n - 1; ++i)
		arr[i] = arr[i + 1] - arr[i];
	--n;

	int subLength = 1;
	int length = 1;
	int pos = 0;
	int subPos = 0;

	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > arr[i - 1])
		{
			++length;
		}
		else
		{
			if (subLength < length)
			{
				subLength = length;
				subPos = pos;
			}

			length = 1;
			pos = i;
		}
	}

	if (subLength < length)
	{
		subLength = length;
		subPos = pos;
	}


	for (int i = subPos; i < subPos + subLength; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	

	free(arr);

	return 0;
}

