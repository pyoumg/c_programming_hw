#include <stdio.h>

int main()
{
	int c=1,d;
	enum operator
	{
			PLUS=1,MINUS,MUL,DIV,POW
	};
	
	scanf("%d",&d);
	
	int a,b;
	scanf("%d %d",&a,&b);
	switch(d)
	{
		case PLUS:
				printf("%d",a+b);
				break;
		case MINUS:
				printf("%d",a-b);
				break;
		case MUL:
				printf("%d",a*b);
				break;
		case DIV:
				if(b!=0)
				{
				printf("%d",a/b);
				}
				break;
		case POW:
				
				for(int i=0;i<b;i++)
				{
						c=c*a;
				}
				printf("%d",c);
				break;
		default:
				break;

	}

	printf("\n");

	return 0;
}
