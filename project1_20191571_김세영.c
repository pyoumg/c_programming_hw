#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int INT(char*, char**, int*, int);
void CAL(char*, char*, char**, int*, int);
void PRINT_VARS(char**, int*, int);
void PRINT(char*, char**, int*, int);

/*
	main
	 -this function reads command
	- it performs different functions according to the command

	parameters
	- i: the number of elements of array 'num1','num2'
	- n: the length of string 'com'
	- num1: the array that stores variable names
	- num2: the array that stores variable's value
	- com: the command
	- op1: the string that is front part of command
	-op2: the string that is second part of command


	return value: 0(program ends)
*/
int main()
{
	int i = 0, n;
	int *num2;
	char **num1, *com, op1[30], op2[30];


	com = (char*)malloc(sizeof(char) * 129);
	num1 = (char**)malloc(sizeof(char*) * 33);

	for (int j = 0; j < 33; j++)
	{
		num1[j] = (char*)malloc(sizeof(char) * 31);
	}

	num2 = (int*)malloc(sizeof(int) * 33);

	while (1)
	{
		op1[0] = 'a', op2[0] = 'a';
		printf(">> ");
		fgets(com, sizeof(char) * 129, stdin);
		n = strlen(com);
		com[n - 1] = '\0';
		sscanf(com, "%s %s %*s", op1, op2);

		if (strcmp(op1, "INT") == 0)
		{
			i = INT(com, num1, num2, i);
		}
		else if (strcmp(op1, "PRINT") == 0)
		{
			PRINT(com, num1, num2, i);
		}
		else if (strcmp(com, "PRINT_VARS") == 0)
		{
			PRINT_VARS(num1, num2, i);
		}
		else if (strcmp(com, "EXIT") == 0)
		{
			break;
		}
		else if (strcmp(op2, "+") == 0 || strcmp(op2, "-") == 0 || strcmp(op2, "*") == 0 || strcmp(op2, "/") == 0)
		{
			CAL(op2, com, num1, num2, i);
		}
		else
			printf("error\n");
	}

	free(com);
	for (int j = 0; j < 33; j++)
	{
		free(num1[j]);
	}
	free(num1);
	free(num2);

	return 0;
}


/*
	INT
	- this function stores integer value and variable name

	 parameter

	 -com: the command
	 - num1: the array that stores variable names
	- num2: the array that stores variable's value
	- i:  the number of elements of array 'num1','num2'
	 -num: if 'n'is integer value, num is equal to 'n'
		num is integer value that is new variable's value
	 -n:the string that is the last part of command to check if it is integer value



	 return value: i;the number of elements of array 'num1','num2'



*/

int INT(char* com, char** num1, int* num2, int i)
{
	char num[30];
	double n;
	sscanf(com, "%*s %*s %lf", &n);

	if ((double)(n - (int)n) == 0)
	{

		sscanf(com, "%*3c %s %s", num1[i], num);
		{

			for (int j = 0; j < strlen(num); j++)
			{
				if (num[j] < '0'&&num[0] != '-' || (num[j] > '9'&&num[0] != '-'))
				{
					printf("error\n");
					break;
				}
				else if (j == strlen(num) - 1)
				{
					num2[i] = atoi(num);
					i++;
				}
			}
		}

	}
	else
		printf("error\n");
	return i;
}



/*

	CAL
	-this function calculate and print the value using the operators

	parameters
	-op2: the middle part of command
	-com: the command
	- num1: the array that stores variable names
	- num2: the array that stores variable's value
	- i: the number of elements of array 'num1','num2'

	-n1: the first part of command
	-n2: the last part of command
	-op: the operator to calculate

	-n3: the integer value that is actually calculated
	-n4: the integer value that is actually calculated


	return value : none
*/
void CAL(char* op2, char* com, char** num1, int* num2, int i)
{
	char n1[30], n2[30];
	int n3, n4;
	char op = op2[0];


	sscanf(com, "%s %*c %s", n1, n2);

	for (int j = 0; j < i; j++)
	{
		if ((strncmp(n1, num1[j], strlen(num1[j])) == 0))
		{
			n3 = num2[j];
			break;
		}
		else if (j == i - 1)
		{
			for (int x = 0; x < strlen(n1); x++)
			{
				if (n1[x] < '0'&&n1[0] != '-' || (n1[x] > '9'&&n1[0] != '-'))
				{
					printf("error\n");
					return;
				}
			}

			n3 = atoi(n1);
		}
	}
	for (int j = 0; j < i; j++)
	{
		if ((strncmp(n2, num1[j], strlen(num1[j])) == 0))
		{
			n4 = num2[j];
			break;
		}
		else if (j == i - 1)
		{
			for (int x = 0; x < strlen(n2); x++)
			{

				if (n2[x] < '0'&&n2[0] != '-' || (n2[x] > '9'&&n2[0] != '-'))
				{
					printf("error\n");
					return;
				}
			}
			n4 = atoi(n2);
		}
	}

	if (i == 0)
	{
		for (int x = 0; x < strlen(n1); x++)
		{
			if (n1[x] < '0'&&n1[0] != '-' || (n1[x] > '9'&&n1[0] != '-'))
			{
				printf("error\n");
				return;
			}
		}
		n3 = atoi(n1);
		for (int x = 0; x < strlen(n2); x++)
		{

			if (n2[x] < '0'&&n2[0] != '-' || (n2[x] > '9'&&n2[0] != '-'))
			{
				printf("error\n");
				return;
			}
		}
		n4 = atoi(n2);
	}


	if (op == '+')
	{

		printf("%d\n", n3 + n4);
	}
	else if (op == '-')
	{
		printf("%d\n", n3 - n4);
	}
	else if (op == '*')
	{
		printf("%d\n", n3*n4);
	}
	else if (op == '/')
	{
		if (n4 == 0)
			printf("error\n");
		else
			printf("%d\n", n3 / n4);
	}
	return;
}

/*
	PRINT_VARS
	- this function prints the name of all stored variables and their value


	parameters
	- num1: the array that stores variable names
	- num2: the array that stores variable's value
	- i:  the number of elements of array 'num1','num2'

	return value: none
*/

void PRINT_VARS(char** num1, int* num2, int i)
{
	for (int j = 0; j < i; j++)
	{
		printf("%s=%d\n", num1[j], num2[j]);
	}
	if (i == 0)
		printf("empty\n");

	return;
}


/*
	PRINT
	-this function searches the name of variable if it is in the arr 'num1' and prints a stored variable


	parameters
	-com:the command
	- num1: the array that stores variable names
	- num2: the array that stores variable's value
	- i: the number of elements of array 'num1','num2'

	-var: the last part of the command

	return value : none
*/
void PRINT(char* com, char** num1, int* num2, int i)
{
	char var[30];
	sscanf(com, "%*5c %s", var);
	for (int j = 0; j < i; j++)
	{
		if (strncmp(var, num1[j], sizeof(var) - 1) == 0)
		{
			printf("%d\n", num2[j]);
			return;
		}
		else if (j == i - 1)
		{
			printf("not found\n");
			return;
		}

	}

	if (i == 0)
	{
		printf("not found\n");
		return;
	}
	return;
}