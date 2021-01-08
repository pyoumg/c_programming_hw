#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int a,b,i=0,j=0,replace=0;
	char *str,c='\0';
	char *old,*new;
	str=(char*)malloc(sizeof(char)*100001);
	old=(char*)malloc(sizeof(char)*128);
	new=(char*)malloc(sizeof(char)*128);
	

	FILE* fp1,*fp2;
	fp1=fopen("input_p1.txt","r");	
	fp2=fopen("output_p1.txt","w");
	while(1)
	{
		str[i]=fgetc(fp1);
		if(str[i]==EOF)
				break;
		i++;
	}
	i=0;
	
	fgets(old,sizeof(char)*128,stdin);
	fgets(new,sizeof(char)*128,stdin);
	a=strlen(old)-1;
	
	b=strlen(new)-1;
//   printf("%d\n%d\n",a,b);

	while(1)
	{
		if(str[i]==EOF)
			break;	

		if((strncmp(old,str+i,a))!=0)	
		{
				fprintf(fp2,"%c",str[i]);	
				
		}	
		else
		{
				for(int k=0;k<b;k++)
				{
						
						fprintf(fp2,"%c",new[k]);
						
						
				}
				
				replace++;
				i=i+a-1;
		}
		
		i++;

	}
		
	
	printf("%d\n",replace);
	
	free(str);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
