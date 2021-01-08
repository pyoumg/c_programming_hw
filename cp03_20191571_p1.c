#include <stdio.h>

int find_value(int*,int*,int);

int main()
{
	int *start,*end,size,target,arr[1000],a,b,c;
	
	scanf("%d",&size);
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	
	}
		
		scanf("%d %d %d",&a,&b,&target);
		start=&arr[a];
		end=&arr[b];

	if(find_value(start,end,target)==1)
			printf("True\n");
	else 
			printf("False\n");



	return 0;
}

int find_value(int* start,int* end,int target)
{
	while(start!=end)
	{
			
		if(*start==target)
				return 1;
		start=&start[1];
		
	}
	 if(*end==target)
			 return 1;
	 else
			 return 0;

}
