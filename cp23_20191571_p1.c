#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
	korean = 0, japanese, chinese
}food_style;

typedef struct __Food {
	int number;
	char name[20];
	food_style style;
	int cooking_time;
}Food;

typedef struct __Order* nptr;

typedef struct __Order {
	Food *pfood;
	int waiting_time;
	nptr order_link;
	nptr style_link;
}Order;

nptr order_front = NULL;
nptr order_rear = NULL;
nptr style_front[3] = { NULL, };
nptr style_rear[3] = { NULL, };


Food* fd;
nptr nOrder;

void print_order();
void order_cal(int, int*);


int main()
{

	int food_number = 0, order_number = 0;
	int *order_food;
	char style[20];
	FILE* fp = fopen("menu.txt", "r");
	fscanf(fp, "%d", &food_number);
	
	fd = (Food*)malloc(sizeof(Food)*food_number);
	for (int i = 0; i < food_number; i++)
	{
		fscanf(fp, "%d %s %s %d", &fd[i].number, fd[i].name,style, &fd[i].cooking_time);
		if (strcmp(style, "korean") == 0)
			fd[i].style = 0;
		else if (strcmp(style, "japanese") == 0)
			fd[i].style = 1;
		else
			fd[i].style = 2;

	}
	scanf("%d", &order_number);
	

	order_food = (int*)malloc(sizeof(int)*order_number);
	for (int i = 0; i < order_number; i++)
	{
		scanf("%d", &order_food[i]);
	}
	order_cal(order_number, order_food);
	print_order();

	fclose(fp);
}

void order_cal(int order_number, int* order_food)
{
	for (int i = 0; i < order_number; i++)
	{
		nOrder = (Order*)malloc(sizeof(Order));
		if (i == 0)
		{
			order_front = nOrder;
			order_rear = nOrder;
			nOrder->order_link = NULL;
		}
		else
		{
			order_rear->order_link = nOrder;
			order_rear = nOrder;
			nOrder->order_link = NULL;

		}
		nOrder->pfood = &fd[order_food[i]];
		
		if (style_front[nOrder->pfood->style] == NULL)
		{

				//여기서 1~4줄 주석처리 하면..???
			style_front[nOrder->pfood->style] = (Order*)malloc(sizeof(Order));
			style_rear[nOrder->pfood->style] = (Order*)malloc(sizeof(Order));
			style_front[nOrder->pfood->style]->waiting_time = nOrder->pfood->cooking_time;
			style_rear[nOrder->pfood->style]->waiting_time = nOrder->pfood->cooking_time;
			nOrder->waiting_time = nOrder->pfood->cooking_time;

			style_front[nOrder->pfood->style] = nOrder;
			style_rear[nOrder->pfood->style] = nOrder;
			nOrder->style_link = NULL;

		}
		else
		{
			
			nOrder->waiting_time = style_rear[nOrder->pfood->style]->waiting_time+nOrder->pfood->cooking_time;
			style_rear[nOrder->pfood->style] = nOrder;
			nOrder->style_link = NULL;
			
		}
		
	

	}


}

void print_order()
{
	printf("Order List\n");
	int i = 1;
	for (nptr cur = order_front; cur; cur = cur->order_link, i++)
		printf("#%2d %15s %2d %3d\n", i, cur->pfood->name, cur->pfood->cooking_time, cur->waiting_time);
}
