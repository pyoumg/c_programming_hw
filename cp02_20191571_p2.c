
#include <stdio.h>
void Adder(void*, void*, char);
int main()
{
	char a;

	double n1, n2;
	int n3, n4;
	scanf("%c", &a);
	
	if (a == 'd')
	{

		scanf("%lf %lf", &n1, &n2);
		Adder(&n1, &n2, a);
	}
	if (a == 'i')
	{

		scanf("%d %d", &n3, &n4);
		Adder(&n3,&n4,a);
	}

	return 0;

}

void Adder(void* num1, void* num2, char option)
{
	int*n1, *n2;
	double*n3,*n4;
	if (option == 'i')
	{
		n1 = num1;
		n2 = num2;
		printf("%d", *n1 + *n2);
	}
	if (option == 'd')
	{
		n3 = num1;
		n4 = num2;
		printf("%lf",*n3 +*n4);

	}


	return;
}

