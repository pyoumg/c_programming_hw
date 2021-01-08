#include <stdio.h>
#include <stdlib.h>

void InsertNode(char target, char a);
void DeleteNode(char);
void PrintList();

typedef struct _NODE {
	char Data;
	struct _NODE *LINK;


}NODE;
NODE *head = NULL;

NODE* pNew, *pPre, *temp,*tail = NULL;

void main()
{

	InsertNode('a', 'c');
	InsertNode('a', 'm');
	InsertNode('c', 'o');
	InsertNode('a', 'p');
	InsertNode('a', 't');
	InsertNode('p', 'u');
	InsertNode('t', 'e');
	InsertNode('a', 'r');
	PrintList();
	DeleteNode('a');
	DeleteNode('c');
	DeleteNode('o');
	DeleteNode('p');
	PrintList();

}

void InsertNode(char target, char a)
{
	if (head == NULL)
	{
		head = (NODE*)malloc(sizeof(NODE));

		head->LINK = tail;

		temp = (NODE*)malloc(sizeof(NODE));
		pPre = (NODE*)malloc(sizeof(NODE));
	}

	pNew = (NODE*)malloc(sizeof(NODE));
	pPre = head;
	while (pPre->LINK != NULL)
	{
		if (pPre->Data == target)
		{
			break;
		}
		else if (pPre->LINK != NULL)
			pPre = pPre->LINK;
		else
			break;
	}

	pNew->Data = a;
	pNew->LINK = pPre->LINK;
	pPre->LINK = pNew;


}

void DeleteNode(char target)
{
	pPre = head;
	while (pPre->LINK->Data != target)
	{
		if (pPre->LINK->LINK != NULL)
			pPre = pPre->LINK;
		else
			break;
	}
	temp = pPre->LINK;
	pPre->LINK = pPre->LINK->LINK;
	free(temp);
}

void PrintList()
{
	pPre = head->LINK;
	while (pPre != tail)
	{
		printf("%c", pPre->Data);
		pPre = pPre->LINK;
	}
	printf("\n");

}