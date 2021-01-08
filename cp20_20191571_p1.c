#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
	int value;
	struct __node* next;
} NODE;

NODE* head;
NODE* tail;

void initHeadTail();
void insertNode(int);
void printNode();

NODE *node1;
NODE *pNew, *pPrev;

int main()
{
	int n;
	head=(NODE*)malloc(sizeof(NODE));
	tail=(NODE*)malloc(sizeof(NODE));
	node1 = (NODE*)malloc(sizeof(NODE));
	node1 = head;
	
	pPrev = head;
	initHeadTail();
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &n);
		insertNode(n);
	}
	printNode();

	return 0;
}

void initHeadTail()
{
	head->value = -1;
	tail->value = -1;
	head->next = tail;
	tail->next = NULL;
}

void insertNode(int n)
{
	
	pNew = malloc(sizeof(NODE));
	pNew->next = tail;
	pNew->value = n;
	pPrev->next = pNew;
	pPrev = pPrev->next;

}

void printNode()
{

	for (int i = 0; i < 7; i++)
	{
		if (i != 0 && i != 6)
			printf("%d ", node1->value);
		node1 = node1->next;
	}


}
