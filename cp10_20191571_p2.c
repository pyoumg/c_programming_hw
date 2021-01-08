#include <stdio.h>
#include <stdlib.h>

void str_sort(char*);

int main()
	{
		char* str1,*str2;

		int n=0,j=0;
		str1=(char*)malloc(sizeof(char)*31);
		str2=(char*)malloc(sizeof(char)*16);

		scanf("%s",str1);
		scanf("%s",str2);
		
		for(int i=0;i<16;i++)
		{
			if(str1[i]=='\0')
			{	n=i;
				break;
			}
		}


		for(int i=n;i<32;i++)
		{
				str1[i]=str2[j];
				if(str2[j]=='\0')
				{	
						break;
				}
				j++;
			
		}
		str_sort(str1);


		free(str1);
		free(str2);		
		return 0;


	}

void str_sort(char* str)
{
	char temp;
	int n=0;
	for(int i=0;i<32;i++)
	{
		if(str[i]=='\0')
		{
			n=i;
			break;
		}

	}
	
	for(int i=0;i<n;i++)
	{
			for(int j=0;j<n-1-i;j++)
			{
				if(str[j]>str[j+1])
				{
					temp=str[j];
					str[j]=str[j+1];
					str[j+1]=temp;

				}

			}
	}
	printf("%s\n",str);

	return;


}
