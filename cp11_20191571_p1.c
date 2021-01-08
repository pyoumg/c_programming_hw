#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
	char arr[5][15];
	int arr2[5];
	int temp=0;
	char arr3[15]={};
	for(int i=0;i<5;i++)
	{
		scanf("%s",arr[i]);
		arr2[i]=strlen(arr[i]);

	}
	for(int i=0;i<5;i++)
	{
			for(int j=0;j<4-i;j++)
			{
				if(arr2[j]>arr2[j+1])
				{
					strcpy(arr3,arr[j]);
					strcpy(arr[j],arr[j+1]);
					strcpy(arr[j+1],arr3);
					
					temp=arr2[j];
					arr2[j]=arr2[j+1];
					arr2[j+1]=temp;

				}

				else if(arr2[j]==arr2[j+1])
				{
					for(int k=0;k<arr2[j];k++)
					{
						if(arr[j][k]>arr[j+1][k])
						{
								strcpy(arr3,arr[j]);
								strcpy(arr[j],arr[j+1]);
								strcpy(arr[j+1],arr3);
								break;
						}

					}

				}



			}
	}

	for(int i=0;i<5;i++)
	{
			printf("%s\n",arr[i]);
	}


	return 0;
}
