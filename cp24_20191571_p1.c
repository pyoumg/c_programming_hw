#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CNT 5

typedef struct __NODE* NODE_P;
typedef struct __NODE {
	char command[10];
	NODE_P next;
}NODE;

typedef struct {
	int count;
	NODE_P front;
	NODE_P rear;
}queue;

queue* command_list;
NODE_P pNew;

void init_queue();
//Do NOT use dequeue in print_queue()
void print_queue();
void enqueue(char* command);
void dequeue();

int main() {
	/*if "quit", terminate program
	  if "history", print history of most recent 5 commands*/
	char com[30];
	init_queue();
	while (1)
	{
		printf(">>");
		scanf("%s", com);
		if (strcmp(com, "quit") == 0)
			break;
		else if (strcmp(com, "history") == 0)
		{
			
		
			print_queue();
			enqueue(com);
		}
		else
		{
			enqueue(com);
		}
		
	}
	NODE_P temp=command_list->front;
	while (command_list->count!=0)
	{
		dequeue();
	}
	free(command_list);
	return 0;
}

void init_queue()
{
	command_list = (queue*)malloc(sizeof(queue));
	command_list->front = NULL;
	command_list->rear = NULL;
	command_list->count = 0;
}

void print_queue()
{
	NODE_P temp = command_list->front;
	if (command_list->count == 0)
	{
		printf("NO HISTORY!\n");
		return;
	}
	for(int i=0;i<command_list->count;i++)
	{
		printf("%d : %s\n",i+1, temp->command);
		temp = temp->next;
		

	}
}

void enqueue(char* command)
{
	NODE_P temp=command_list->front;
	pNew = (NODE*)malloc(sizeof(NODE));
	if (command_list->front == NULL)
	{
		command_list->front = pNew;
		command_list->rear = pNew;
		command_list->count++;
		strcpy(pNew->command, command);
	}
	else
	{
		
		command_list->rear->next = pNew;
		
		command_list->rear = pNew;
		strcpy(pNew->command, command);
		command_list->count++;
		if (command_list->count > MAX_CNT)
			dequeue();

	}
	


}

void dequeue()
{
	NODE_P temp=command_list->front;
	command_list->front = command_list->front->next;
	free(temp);
	command_list->count--;
}
