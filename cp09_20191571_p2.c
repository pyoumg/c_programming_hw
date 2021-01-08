#include <stdio.h>
#include <stdlib.h>

int my_strstr(char* origin, char* pattern);
int main()
	{
		char* origin=(char*)malloc(sizeof(char)*11);
		char* pattern=(char*)malloc(sizeof(char)*11);
		scanf("%s",origin);
		scanf("%s",pattern);

		printf("%d\n",my_strstr(origin,pattern));
		free(origin);
		free(pattern);

		return 0;



	}

int my_strstr(char* origin, char* pattern)
{
		int k=0;
		for(int i=0;i<=10;i++)
		{
			if(*(origin+i)==*(pattern))
			{
				for(int j=i;j<=10;j++)
				{	
					if(*(pattern+k)==0)
							return i;
					else if(*(origin+j)==*(pattern+k))
					{	
							k++;

					}
					else
							return -1;
					
				}



			}

		if(*(origin+i)==0)
				return -1;

		}

	return -1;



}
