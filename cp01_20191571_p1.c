#include <stdio.h>

void sum_and_diff(int, int, int*, int*);

int main()
{
	int a, b;
	printf("Input two integers: ");
	scanf("%d %d", &a, &b);
	sum_and_diff(a, b, &a, &b);
	printf("a + b : %d , ", a);
	printf("a - b: %d\n", b);


	return 0;
}

void sum_and_diff(int a, int b, int* sum, int* diff)
{
	*sum = a + b;
	*diff = a - b;

	return;

}