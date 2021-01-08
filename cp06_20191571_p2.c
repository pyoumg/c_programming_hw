#include <stdio.h>
#include <stdlib.h>

void copy_str(char* dest,char* src);

int main()
	{
		char *a,*b;
		for(int i=0;i<11;i++)
		{
				scanf("%c",&a[i]);
				if(a[i]=='\n')
				{
					a[i]='\0';
						break;

				}
		}


		b=(char*)malloc(11*sizeof(char));
		copy_str(b,a);
		printf("%s\n",b);



	return 0;
	}

void copy_str(char* dest, char* src)
{
	for(int i=0;i<11;i++)
	{
		dest[i]=src[i];
		if(src[i]=='\0')
				break;


	}




}


