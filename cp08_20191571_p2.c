#include <stdio.h>
#include <stdlib.h>
size_t alloc = 0;

void* my_malloc(size_t);
int pascal(int, int);

int main()
{
	int n;
	int *p1;
	scanf("%d", &n);
	p1= my_malloc(n);

	return 0;
}

void* my_malloc(size_t Size)
{
	int* arr[31];
	for (int i = 0; i < Size; i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*(i + 1));
	}

	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			*(arr[i] + j) = pascal(i, j);
				alloc = alloc + sizeof(arr[i][j]);

		}
	}

	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	printf("%zu\n", alloc);

	for(int i=0;i<Size;i++)
	{
			free(arr[i]);
	}

	return *arr;
}


int pascal(int a, int b) 
{
	if (a == 0 || b == 0 || a == b)
		return 1;
	else
		return pascal(a - 1, b) + pascal(a - 1, b - 1);
}
