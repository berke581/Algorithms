#include <stdio.h>


int maxProfit(int* arr, int b, int s);

int main() {
	int arr[20];
	
	int arrSize = 0;
	int element;
	while (scanf("%d, ", &element) != EOF)
		arr[arrSize++] = element;
	
	printf("%d\n", maxProfit(arr, 0, arrSize - 1));
	
	return 0;
}


int maxProfit(int* arr, int b, int s)
{
	if (s <= b)
		return 0;
	
	int profit = 0;
	
	for (int i = b; i <= s; ++i)
	{
		for (int j = i + 1; j <= s; ++j)
		{
			if (arr[j] > arr[i])
			{
				int newProfit = arr[j] - arr[i] + maxProfit(arr, b, i - 1) + maxProfit(arr, j + 1, s);
				
				if (newProfit > profit)
					profit = newProfit;
			}
		}
	}
	
	return profit;
}

