#include<stdio.h>
void tow(int n, char A, char B, char C)
{
	if(n >= 1)
	{
		tow(n-1, A, C, B);
		printf("move %c to %c\n", A, C);
		tow(n-1, B, A, C);
	}
}
int main()
{
	int n;
	printf("Enter the no. disk ");
	scanf("%d", &n);
	tow(n, 'A', 'B', 'C');
}
