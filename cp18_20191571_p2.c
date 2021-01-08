#include <stdio.h>
typedef enum {
	INTEGER = 0, REAL, NAN

}Type;

typedef struct __Number {
	Type t;
	union {
		int i;
		double r;
	}data;

}Number;

typedef enum {
	ADD = 0, SUB, MUL, DIV
}Operation;

Number calculate(Number n1, Number n2, Operation op);
Number n1, n2, n3;
int main()
{
	double a, b;
	scanf("%lf %lf", &a, &b);
	if ((int)a - a == 0)
	{
		n1.t = 0;
		n1.data.i = a;
	}
	else
	{
		n1.t = 1;
		n1.data.r = a;
	}
	if ((int)b - b == 0)
	{
		n2.t = 0;
		n2.data.i = b;
	}
	else
	{
		n2.t = 1;
		n2.data.r = b;
	}
	for (int i = 0; i < 4; i++)
	{
		n3 = calculate(n1, n2, i);
		if (i == 0)
			printf("ADD ");
		else if (i == 1)
			printf("SUB ");
		else if (i == 2)
			printf("MUL ");
		else
			printf("DIV ");
		if (n3.t == 0)
		{
			printf("%d INTEGER\n", n3.data.i);
		}
		else if (n3.t == 1)
			printf("%lf REAL\n", n3.data.r);
		else
			printf("NAN\n");
	}
	return 0;
}

Number calculate(Number n1, Number n2, Operation op)
{
	Number n3;
	double i;
	switch (op)
	{
	case 0:
		if (n1.t == 0 && n2.t == 0)
		{
			n3.t = 0;
			n3.data.i = n1.data.i + n2.data.i;
		}
		else if (n1.t == 1 && n2.t == 0)
		{
			n3.t = 1;
			n3.data.r = n1.data.r + n2.data.i;
		}
		else if (n1.t == 0 && n2.t == 1)
		{
			n3.t = 1;
			n3.data.r = n1.data.i + n2.data.r;
		}
		else
		{
			i = n1.data.r + n2.data.r;
			if ((int)i - i == 0)
			{
				n3.t = 0;
				n3.data.i = i;


			}
			else
			{
				n3.t = 1;
				n3.data.r = i;
			}
		}
		break;

	case 1:
		if (n1.t == 0 && n2.t == 0)
		{
			n3.t = 0;
			n3.data.i = n1.data.i - n2.data.i;
		}
		else if (n1.t == 1 && n2.t == 0)
		{
			n3.t = 1;
			n3.data.r = n1.data.r - n2.data.i;
		}
		else if (n1.t == 0 && n2.t == 1)
		{
			n3.t = 1;
			n3.data.r = n1.data.i - n2.data.r;
		}
		else
		{
			i = n1.data.r - n2.data.r;
			if ((int)i - i == 0)
			{
				n3.t = 0;
				n3.data.i = i;


			}
			else
			{
				n3.t = 1;
				n3.data.r = i;
			}
		}
		break;

	case 2:
		if (n1.t == 0 && n2.t == 0)
		{
			n3.t = 0;
			n3.data.i = n1.data.i * n2.data.i;
		}
		else if(n1.t==0&&n2.t!=0)
		{
			n3.t = 1;
			n3.data.r = n1.data.i * n2.data.r;

		}
		else if (n1.t != 0 && n2.t == 0)
		{
			n3.t = 1;
			n3.data.r = n1.data.r*n2.data.i;
		}
		else
		{
			n3.t = 1;
			n3.data.r = n1.data.r*n2.data.r;
		}
		break;
	case 3:
	if (n2.data.i == 0 && n2.t == 0)

		{
			n3.t = 2;
		}
	else
	{

		if (n1.t == 0 && n2.t == 0)
		{

			i = n1.data.i / n2.data.i;
		}
		else if (n1.t == 1 && n2.t == 0)
		{
			i = n1.data.r / n2.data.i;
		}
		else if (n1.t == 0 && n2.t == 1)
		{
			i = n1.data.i / n2.data.r;
		}
		else
		{
			i = n1.data.r / n2.data.r;
		}
		if ((int)i - i == 0)
		{
			n3.t = 0;
			n3.data.i = i;
		}
		else
		{
			n3.t = 1;
			n3.data.r = i;
		}
		
		if(n1.t==0&&n2.t==0)
		{
				n3.data.r=i;
				n3.t=1;
		}
	}
		break;
	}


	return n3;
}
