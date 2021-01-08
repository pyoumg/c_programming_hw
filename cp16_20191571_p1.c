#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	float mid;
	float fin;
	float proj;

}Points;

typedef struct {

	char name[40];
	int studentid;
	char grade[3];
	float total_score;
	Points p;


}Grades;
Grades *st, temp;
int main()
{

	FILE* fp;
	int n, i = 0;
	float a, b;

	fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &n);
	st = (Grades*)malloc(sizeof(Grades)*n);
//	st2 = (Grades*)malloc(sizeof(Grades)*n);
	

	for(i=0;i<n;i++)
	{
	
		fscanf(fp, "%d", &st[i].studentid);
		fscanf(fp, "%s", st[i].name);
		fscanf(fp, "%f", &st[i].p.mid);
		fscanf(fp, "%f", &st[i].p.fin);
		fscanf(fp, "%f", &st[i].p.proj);

	}


	for (int j = 0; j < n; j++)
	{

		st[j].total_score = st[j].p.mid*0.3 + st[j].p.fin*0.3 + st[j].p.proj*0.4;
	}


	temp.total_score=0;
	for (int j = 0; j < n; j++)
	{
		
		for (int k = j; k < n; k++)
		{
			if (st[k].total_score >st[j].total_score )
			{
				temp=st[j];
				st[j] = st[k];
				st[k]=temp;
			}

		}
	}



	printf("-- Student List --\n\n");
	for (i = 0; i < n; i++)
	{
		printf("Id : %d\n", st[i].studentid);
		printf("Name : %s\n", st[i].name);
		printf("Score(mid) : %.2f\n", st[i].p.mid);
		printf("Score(final) : %.2f\n", st[i].p.fin);
		printf("Score(project) : %.2f\n", st[i].p.proj);
		printf("Grade : ");
		if ((i + 1) <= (n + i)*0.3&&st[i].total_score >= 50)
		{
			printf("A ");
		}
		else if ((i + 1) > (n + i)*0.3 && (i + 1) <= (n + i)*0.7&&st[i].total_score >= 50)
		{
			printf("B ");
		}
		else if (st[i].total_score >= 50)
		{
			printf("C ");

		}
		else
			printf("F ");
		printf("(%.2f, %d)\n", st[i].total_score, i+1);
		printf("\n");

	}

	free(st);
	
	fclose(fp);
	return 0;
}
