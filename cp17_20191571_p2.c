#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//65 90 97 122 
typedef struct __Person{
	char name[50];
	char email[50];
	int valid;


}Person;

void CheckEmailName(Person* a);

int main()
{	
	Person *stu;
	FILE *fp;
	int n;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&n);
	stu=(Person*)malloc(sizeof(Person)*n);
	
	for(int i=0;i<n;i++)
	{
		fscanf(fp,"%s",stu[i].name);
		fscanf(fp,"%s",stu[i].email);
		stu[i].valid=0;

	}
	CheckEmailName(stu);

	for(int i=0;i<n;i++)
	{
		if(stu[i].valid==1)
		{
			printf("%s\t%s\n",stu[i].name,stu[i].email);
		}
	}


	free(stu);
	fclose(fp);
	return 0;
}

void CheckEmailName(Person* a)
{
	int k=0,p=0,k1,p1,s;
	int n=sizeof(a);
	
	for(int i=0;i<n;i++)
	{
			k=0,p=0;
			s=strlen(a[i].email);
//			printf("%d\n",strlen(a[i].email));
		for(int j=0;j<s;j++)
		{
			if(a[i].email[j]=='@')
		{
				k++;
				k1=j;
		}
			else if(a[i].email[j]=='.')
			{	
					p++;
					p1=j;
			
			}
			else if(a[i].email[j]<'A'||a[i].email[j]>'Z')
			{
					if(a[i].email[j]<'a'||a[i].email[j]>'z')
							break;
			}
		}	
	//	s=strlen(a[i].email);
		if(k==1&&p==1&&k1+1<p1&&p1!=s-1&&k1!=0)
		{
				a[i].valid=1;
		}
		
	}



	return;
}
