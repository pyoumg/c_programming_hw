#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
	int value_tongue;
	int value_elbow;
	struct __node* next_tongue;
	struct __node* next_elbow;
} NODE;

NODE* head_tongue;
NODE* tail_tongue;

NODE* head_elbow;
NODE* tail_elbow;

void initHeadTail();
void insertNode(int, int);
void printTongue();
void printElbow();

NODE* pNew,*ptr1,*ptr2,*node1;


int main()
{
	node1 = (NODE*)malloc(sizeof(NODE));
	ptr1 = (NODE*)malloc(sizeof(NODE));
	ptr2 = (NODE*)malloc(sizeof(NODE));


	initHeadTail();
	int n1, n2;
	ptr1= head_elbow;
	ptr2= head_tongue;
	for (int i = 0; i < 5; i++)
	{
		printf("input a tongue and elbow node!\n");
		printf("input a tongue length : ");
		scanf("%d", &n1);
		printf("input a elbow length : ");
		scanf("%d", &n2);
		insertNode(n1, n2);
		printf("\n");
	}
	printTongue();
	printf("\n");
	printElbow();



	return 0;
}


void initHeadTail()
{
	head_tongue = (NODE*)malloc(sizeof(NODE));
	tail_tongue = (NODE*)malloc(sizeof(NODE));
	head_elbow = (NODE*)malloc(sizeof(NODE));
	tail_elbow = (NODE*)malloc(sizeof(NODE));
	head_tongue->value_tongue = -1;
	head_elbow->value_elbow = -1;
	head_elbow->next_elbow = tail_elbow;
	head_tongue->next_tongue = tail_tongue;

}
void insertNode(int n1, int n2)
{
	pNew = (NODE*)malloc(sizeof(NODE));


	pNew->value_elbow = n2;
	pNew->value_tongue = n1;
	
	ptr1 = head_elbow;
	ptr2 = head_tongue;

	if (head_elbow->next_elbow == tail_elbow)
	{
		head_elbow->next_elbow = pNew;
		pNew->next_elbow = tail_elbow;
		head_tongue->next_tongue = pNew;
		pNew->next_tongue = tail_tongue;
	}

	else
	{
		while (ptr1->next_elbow->value_elbow < pNew->value_elbow&&ptr1->next_elbow != tail_elbow)
		{
			ptr1 = ptr1->next_elbow;
		}
		pNew->next_elbow = ptr1->next_elbow;
		ptr1->next_elbow = pNew;


		while (ptr2->next_tongue->value_tongue < pNew->value_tongue&&ptr2->next_tongue != tail_tongue)
		{
			ptr2 = ptr2->next_tongue;
		}
		pNew->next_tongue = ptr2->next_tongue;
		ptr2->next_tongue = pNew;


	}

}

void printTongue()
{
	node1 = head_tongue->next_tongue;
	printf("Tongue list : ");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", node1->value_tongue);
		node1 = node1->next_tongue;
	}

}
void printElbow()
{
	node1 = head_elbow;
	printf("Elbow list : ");
	for (int i = 0; i < 6; i++)
	{
		if(i!=0)
			printf("%d ", node1->value_elbow);
		node1 = node1->next_elbow;
	}

}
