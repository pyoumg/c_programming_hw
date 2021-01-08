#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{	
		int size1=0,size2=0;
		char name[10],cour[10];
		double time;
		typedef struct{
					char student_name[10];
					char course_name[20];
			}student;
		typedef struct{
				char course_name[20];
				double running_time;

		}course;

		student st[10];
		course cor[10];
		FILE *fp1,*fp2;
		fp1=fopen("student.txt","r");
		fp2=fopen("course.txt","r");
		fscanf(fp1,"%d",&size1);
		fscanf(fp2,"%d",&size2);
		for(int i=0;i<size2;i++)
		{
			fscanf(fp2,"%s %lf",name,&time);
			strcpy(cor[i].course_name,name);
			cor[i].running_time=time;



		}
		

		for(int i=0;i<size1;i++)
		{
			fscanf(fp1,"%s %s",name,cour);
			strcpy(st[i].student_name,name);
			strcpy(st[i].course_name,cour);
			for(int j=0;j<size2;j++)
			{
					if(strcmp(st[i].course_name,cor[j].course_name)==0)
					{
						printf("%s %.1lf\n",st[i].student_name,cor[j].running_time);
					}
			
			}
			
		}
		
	fclose(fp1);
	fclose(fp2);

		return 0;
	}
