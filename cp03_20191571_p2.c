#include <stdio.h>
void sum_array(int*,int*,int*, int);

int main()
{
	int size,arr[1000],*B,*C=arr,*A=arr;
	
	scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	B=&arr[1]; 
	C=&arr[1];
	sum_array(A,B,C,size-1);
	for(int i=0;i<size;i++)
	{
			printf("%d ",arr[i]);
	}

	return 0;

}

void sum_array(int *A,int* B,int*C, int size)
{
	
	for(int i=0;i<size;i++)
	{
		C[i]=A[i]+B[i];

	}
	

}

