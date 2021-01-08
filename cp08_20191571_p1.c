#include <stdio.h>
#include <stdlib.h>

int main()
{
		int*arr[10][10];
		int a,b,c;
		scanf("%d %d %d",&c,&a,&b);
		for(int i=0;i<c;i++)
		{
				for(int j=0;j<a;j++)
				{
						arr[i][j]=(int*)malloc(sizeof(int)*b);
				}
		}

		for(int k=0;k<c;k++)
		{
				for(int i=0;i<a;i++)
				{
						for(int j=0;j<b;j++)
						{
								*(arr[k][i]+j)=k*a*b+i*b+j;
						}
				}
		}




		for(int k=0;k<c;k++)
		{
				for(int i=0;i<a;i++)
				{
						for(int j=0;j<b;j++)
						{

								printf("%d ",arr[k][i][j]);

						}
						printf("\n");
				}
				printf("\n");
		}

		for(int i=0;i<c;i++)
		{
				for(int j=0;j<a;j++)
				{
						free(arr[i][j]);
				}
		}
		return 0;
}


