#include <stdio.h>

void sort_all(int A[][3], int N);


int main()
{
	int A[100][3];
	int size=0;
	scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		scanf("%d %d %d",&A[i][0],&A[i][1],&A[i][2]);
	}
	for(int i=0;i<size;i++)
	{
		sort_all(A,i);
	}
	





	return 0;
}

void sort_all(int A[][3], int N)
	{
		int temp=0;

		if(A[N][0]>A[N][1])
		{
			temp=A[N][0];
			A[N][0]=A[N][1];
			A[N][1]=temp;
					

		}


		if(A[N][1]>A[N][2])
		{
			temp=A[N][1];
			A[N][1]=A[N][2];
			A[N][2]=temp;


		}

		if(A[N][0]>A[N][1])
		{
			temp=A[N][0];
			A[N][0]=A[N][1];
			A[N][1]=temp;



		}

		for(int i=0;i<3;i++)
		{
				printf("%d ",A[N][i]);
		}
		printf("\n");

	}
