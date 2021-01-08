#include <stdio.h>

void delete_char(char* arr,char ch);

int main()
{
	char arr[10],ch;
	scanf("%s\n",arr);
	scanf("%c",&ch);
	delete_char(arr,ch);

	return 0;

}

void delete_char(char* arr,char ch)
{
	
	for(int i=0;i<10;i++)
	{
			if(ch==*(arr+i))
				{
						for(int j=i;j<10;j++)
						{
							*(arr+j)=*(arr+j+1);
						}
						printf("%s\n",arr);
						break;
				}
			if(i==9)
					printf("Not Found\n");

	}
	



}
