#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int search(int *, int, int);

int main()
{
	char ip[128];
	int *arr;
	int size = 2, a = 0, n = 0;

	arr = (int*)calloc(size, sizeof(int));
	fgets(ip, 128, stdin);
	arr[0] = atoi(ip);
	while (1)
	{
		for (int i = (size / 2); i < size; i++)
		{

			fgets(ip, 128, stdin);
			if (*ip == 'q')
			{
				arr[i] = '\0';
				a = i;
				break;

			}
			else
			{
				arr[i] = atoi(ip);
			}

		}
		if (arr[a] == '\0')
		{
			break;
		}
		size = size * 2;

		arr = (int*)realloc(arr, size * sizeof(int));


	}


	qsort(arr, a, sizeof(int), compare);

	scanf("%d", &n);


	for (int i = 0; i < a; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	printf("%d\n",search(arr,a,n));

	free(arr);

	return 0;

}

int compare(const void *a, const void *b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;

	return 0;



}


int search(int* arr,int len,int target)
{
	int first = 0;
	int last = len - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (target == arr[mid])
			return mid;
		else
		{
			if (target > arr[mid])
			{
				first = mid + 1;
			}
			else
				last = mid - 1;

		}
	}
	return -1;


}


