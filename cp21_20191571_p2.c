#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
	char Data;
	struct _NODE *prev;
	struct _NODE *next;
}NODE;

NODE* tail, *head;

void PrintList();
void PrintListReverse();

void main()
{
	head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE));
	NODE* mid = (NODE*)malloc(sizeof(NODE));
	head->Data = 'a', mid->Data = 'b', tail->Data = 'c';
	head->prev = NULL; head->next = mid;
	mid->prev = head; mid->next = tail;
	tail->prev = mid; tail->next = NULL;
	PrintList();
	PrintListReverse();
}

void PrintList()
{
	while (head != NULL)
	{
		printf("%c", head->Data);
		head = head->next;
	}
	printf("\n");
}

void PrintListReverse()
{
	while (tail != NULL)
	{
		printf("%c", tail->Data);
		tail = tail->prev;
	}
	printf("\n");
}