#include <stdio.h>
#include <stdlib.h>

int st[20];
int top = -1;

void stack_push(int);
int stack_pop();
void stack_print();

int main() {
	int option = 0;
	int data;


	printf("<option>\n(push : 1 data) | (pop : 2) | (stack print : 3)\n");
	while (1) {
		scanf("%d", &option);
		if (option == -1)
			break;
		switch (option) {
		case 1:
			scanf("%d", &data);
			stack_push(data);
			break;
		case 2: 
			top=stack_pop();
			break;
		case 3: 
			stack_print();
			break;
		default: printf("Wrong option!\n");
		}
	}
	
	return 0;
}

void stack_push(int data) {
	
	if (top < 19)
	{
		top++;
		st[top] = data;
	}
	else
	{
		printf("stack is full!\n");
		return;

	}
}
int stack_pop() {


	
	if (top == -1)
	{
		printf("stack is empty!\n");
		return top;
	}
	else
	{
		printf("removed data : %d\n", st[top]);

		st[top] = '\0';
		top--;
		return top;
	}

	return top;
}
void stack_print() {
	
	if (top == -1)
	{
		printf("stack is empty!\n");
		return;
	}
	else
	{
		printf("stack_print : ");
		for (int i = top; i >=0; i--)
		{
			printf("%d ", st[i]);
		}
		printf("\n");
	}


}