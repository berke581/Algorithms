#include <stdio.h>

int GCDbyEuclideanAlgorithmRecursively(int x, int y);

int main() {
	int x, y;
	
	scanf("%d%d", &x, &y);
	
	printf("%d", GCDbyEuclideanAlgorithmRecursively(x, y));

	return 0;
}

int GCDbyEuclideanAlgorithmRecursively(int x, int y)
{
	if (x%2 == 0 && y%2 == 0)
	{
		printf("a ");
		return 2 * GCDbyEuclideanAlgorithmRecursively(x/2, y/2);
	}
	else if (x%2 == 0 && y%2 != 0)
	{
		printf("b ");
		return GCDbyEuclideanAlgorithmRecursively(x/2, y);
	}
	else if (y == 0)
	{
		printf("c ");
		return x;
	}
	else if (x >= y)
	{
		printf("d ");
		return GCDbyEuclideanAlgorithmRecursively(y, x-y);
	}

	printf("e ");
	return GCDbyEuclideanAlgorithmRecursively(y, x);
}
