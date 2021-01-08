#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE {
	int data;
	struct _NODE *link;

}NODE;

int main()
{
	

	NODE* head = malloc(sizeof(NODE));
	NODE* node;
	NODE* nn= malloc(sizeof(NODE));
		nn=head;

	NODE* ptr=head;

	while (nn != NULL)
	{

		node = (NODE*)malloc(sizeof(NODE));
		nn->link = node;
		scanf("%d", &nn->data);
		if (nn->data != -1)
		{
			nn = node;
		}
		else
		{
			nn = NULL;
		}

	}



		while (ptr->link->link != NULL)
		{
			printf("%d ", ptr->data);
			ptr = ptr->link;
		}

	
	return 0;
}


