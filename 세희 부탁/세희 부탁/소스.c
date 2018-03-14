#include <stdio.h>


void makePiramid(int a)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a - i - 1; j++)
			printf(" ");
		for (int j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
int main(void)
{
	int height=-1;
	

	printf("Height:"); scanf("%d", &height);
	printf("%d", height);
	if(height<0 || height > 10||height=="\n")
	{
		 scanf("%d", &height); printf("%d", height);
	}
	else makePiramid(height);
	return 0;
}