#include <stdio.h>

void WriteArray(int*,int);
void ReadArray(int*);

int main()
{
	int n=1;
	while(n%4!=0)
	{
		scanf("%d",&n);

	}
	int row=n/4;
 int array[1000];
	for(int i=0;i<row;i++)
	{
			WriteArray(array,i);
			ReadArray(array);
			*array=*(array+4);
	}
	return 0;
}

void WriteArray(int *array,int row)
{
		int i=0;
		for(i=0;i<4;++i)
		{
				*(array+i)=row*4+i+1;
		}
}

void ReadArray(int * array)
{
		int i=0;
		for(i=0;i<4;++i)
		{

				printf("%d ",*(array+i));
		}
	printf("\n");
}
