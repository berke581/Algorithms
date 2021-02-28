#include <stdio.h>


int maxProfit(int* arr, int days);

int main() {
	int arr[20];
	
	int arrSize = 0;
	int element;
	while (scanf("%d, ", &element) != EOF)
		arr[arrSize++] = element;
	
	printf("%d\n", maxProfit(arr, arrSize));
	
	return 0;
}


int maxProfit(int* arr, int days)
{
	if (days == 1)
		return 0;
	
	int profit = 0;
	
	int i = 0;
	while (i < days - 1)
	{
		while ((i < days - 1) && (arr[i + 1] <= arr[i]))
			++i;
		
		if (i == days - 1)
			break;
		
		int localMin = i++;
		
		while ((i < days) && (arr[i] >= arr[i - 1]))
			++i;
		
		int localMax = i - 1;
		
		profit += arr[localMax] - arr[localMin];
	}
	
	return profit;
}

