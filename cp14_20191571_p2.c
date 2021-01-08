#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char s1[10];
	typedef struct{
			int i;
			char s[10];
			float f;


	}arr;	
	arr a;
	arr b;
	
	scanf("%d %s %f",&a.i,s1,&a.f);
	strcpy(a.s,s1);
	b=a;
	printf("%d %s %f\n",b.i,b.s,b.f);

	return 0;
}
