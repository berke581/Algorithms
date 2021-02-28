#include <stdio.h>

void getInputsAndSeparate();

int main() {
	getInputsAndSeparate();

	return 0;
}

void getInputsAndSeparate()
{
	int input, prevInput;
	scanf("%d", &input);

	int state = 0;

	while (input != -1)
	{
		if (state == 0)
		{
			printf("%d", input);
			state = 1;
		}
		else if (state == 1)
		{
			printf(" %d", input);
			
			if (input > prevInput)
				state = 2;
			else
				state = 3;
		}
		else if (state == 2)
		{
			if (input > prevInput)
			{
				printf(" %d", input);
			}
			else
			{
				printf("\n%d", input);
				state = 1;
			}
		}
		else
		{
			if (input < prevInput)
			{
				printf(" %d", input);
			}
			else
			{
				printf("\n%d", input);
				state = 1;
			}
		}

		prevInput = input;
		scanf("%d", &input);
	}
}
