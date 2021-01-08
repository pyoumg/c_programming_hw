#include <stdio.h>
void multi_matrix(int arr[][5],int result[][5]);

int main()
	{
		int arr[5][5], result[5][5]={0,};
		for(int i=0;i<5;i++)
		{
				for(int j=0;j<5;j++)
				{
						scanf("%d",&arr[i][j]);
				}

		}
		multi_matrix(arr,result);
		return 0;
	}
void multi_matrix(int arr[][5],int result[][5])
{
	for(int i=0;i<5;i++)
	{
			for(int j=0;j<5;j++)
			{

				for(int z=0;z<5;z++)
				{

				*(*(result+i)+j)=*(*(result+i)+j)+*(*(arr+z)+j)**(*(arr+i)+z);
				}
			}
	}

	for(int i=0;i<5;i++)
	{
			for(int j=0;j<5;j++)
			{
					printf("%d ",result[i][j]);
			}
			printf("\n");
	}




}
