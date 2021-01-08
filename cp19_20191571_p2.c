#include <stdio.h>
#include <stdlib.h>

typedef struct __NODE{
	int data;
	struct __NODE *link;


}NODE;


NODE *head;
int main()
{
	int temp;
	head=malloc(sizeof(NODE));
	head->link=malloc(sizeof(NODE));
	head->link->link=malloc(sizeof(NODE));
	scanf("%d %d %d",&(head->data),&(head->link->data),&(head->link->link->data));	
	if(head->data>head->link->data)
	{
		temp=head->data;
		head->data=head->link->data;
		head->link->data=temp;
	}
	if(head->link->data>head->link->link->data)
	{
		temp=head->link->data;
		head->link->data=head->link->link->data;
		head->link->link->data=temp;

	}
	if(head->data>head->link->data)
	{
		temp=head->data;
		head->data=head->link->data;
		head->link->data=temp;

	}

	printf("%d %d %d\n",head->data,head->link->data,head->link->link->data);

	return 0;
}
