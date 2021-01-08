#include <stdio.h>
#include <stdlib.h>
int* calculate_next(int*,int);

int main()
{
	int n=0;
	int* pascal_tr;
	pascal_tr[0]=1;
	scanf("%d",&n);
	
	for(int i=0;i<n+1;i++)
	{
		pascal_tr=calculate_next(pascal_tr,i);
		for(int j=0;j<i;j++)
		{
			printf("%d ",pascal_tr[j]);

		}
		printf("\n");
	}

	return 0;

}

int* calculate_next(int* pascal_tr,int current_level)
{

	int* next_level;
	int n=current_level;
	next_level=(int*)malloc(30*sizeof(int));
	for(int i=0;i<n;i++)
	{
		if(i==0||i==n-1)
		{
			next_level[i]=1;
			
		}
		else{
		next_level[i]=pascal_tr[i-1]+pascal_tr[i];
		}
				
		
	}
	
	return next_level;
}
