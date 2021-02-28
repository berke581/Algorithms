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
	
	int next = 1;
	int temp=1;

	int i = 1;
	while (i < n)
	{
		// Daha once gittiklerimizi -1 ile isaretledik
		// eger daha once geldigimiz bir index ise
		// continue ile devam etmesini sagladik, boylece
		// her indexe sadece 1 kez gittigimizden emin olduk
		if (arr[next- 1 ] == -1)
		{
			++i;
			next = i;
			
			// Duruma gore alt satira gectik
			if (arr[next - 1] != -1)
				printf("\n");
				
			continue;
		}
		else
		{
			temp = next;
			
			printf("%d ", temp);
			
			// Bir sonrakine ilerledik
			next = arr[next - 1];
			
			// -1 ile isaretledik
			arr[temp - 1] = -1;
		}
	}
	
	printf("\n");
	
	free(arr);
	
	return 0;
}

