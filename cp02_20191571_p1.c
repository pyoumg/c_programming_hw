
#include <stdio.h>
void Sort(int*, int*, int*);

int main()
{
	int num1, num2, num3;
	scanf("%d %d %d", &num1, &num2, &num3);
	Sort(&num1, &num2, &num3);
	printf("%d %d %d", num1, num2, num3);
}

void Sort(int* num1, int* num2, int* num3)
{
	int temp=0;
	if (*num2 < *num3)
	{
		temp = *num2;
		*num2 = *num3;
		*num3 = temp;
	}
	if (*num1 < *num2)
	{
		temp=*num1;
		*num1 = *num2;
		*num2 = temp;

	}
	
	if (*num2 < *num3)
	{
		temp = *num2;
		*num2 = *num3;
		*num3 = temp;
	}
	return;
}
