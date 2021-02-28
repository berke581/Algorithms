#include <stdio.h>

int flooredLogBase2(int x);

int main() {
    int input;
    scanf("%d", &input);

    printf("%d\n", flooredLogBase2(input));

    return 0;
}

int flooredLogBase2(int x)
{
    int result = 1;
    int count = 0;

    while (result * 2 <= x)
    {
        result *= 2;
        ++count;
    }

    return count;
}
