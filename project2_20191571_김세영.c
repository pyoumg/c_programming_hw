#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE {
	char name[31];
	int value[33];
	int value_number;
	struct _NODE *link;


}NODE;
NODE *head = NULL, *tail = NULL, *pNew, *pPre;


void LIST();
void PRINT();
void INSERT();
void SORT();

/*
	op1를 키보드로 받은 후 op1(input의 맨 앞부분)이 command(LIST,INSERT,PRINT,EXIT,SORT)인 경우
	각각 command에 맞는 함수를 실행하고(EXIT의 경우 프로그램 종료), 그렇지 않은 경우 "error\n"를 출력한다.

	parameter:
	op1- input의 맨 앞부분


	return value:0(프로그램 종료)
*/

int main()
{


	char op1[30];
	while (1)
	{
		op1[0] = ' ';
		printf(">> ");

		scanf("%s", op1);


		if (strcmp(op1, "LIST") == 0)
		{
			LIST();
		}
		else if (strcmp(op1, "PRINT") == -0)
		{
			PRINT();
		}
		else if (strcmp(op1, "INSERT") == 0)
		{
			INSERT();
		}
		else if (strcmp(op1, "SORT") == 0)
		{
			SORT();
		}
		else if (strcmp(op1, "EXIT") == 0)
			break;
		else
			printf("error\n");
	}


	return 0;
}
/*
	변수 이름과 정수값들을 키보드로 받은 후, NODE에 저장한다.

	parameter:

	op- "LIST"를 제외한 input의 뒷부분
	op1- input의 중간 부분 (variable name)
	op2- input의 뒷부분(integer values)
	i- integer values를 character array에서 integer array로 변환할때 반복문을 실행하는데, 이때 0부터 strlen(op)-1까지 array 값을 확인할때 사용하는 변수
	j- 정수값들의 갯수

	return value:NONE



*/
void LIST()
{

	char *op, op1[31], *op2;
	int i = 0, j = 0;
	op2 = (char*)malloc(sizeof(char) * 128);
	op = (char*)malloc(sizeof(char) * 128);

	if (head == NULL)
	{
		head = (NODE*)malloc(sizeof(NODE));
		head->link = tail;
		pPre = head;
	}
	fgets(op, sizeof(char) * 128, stdin);
	sscanf(op, "%s %*s", op1);
	if (strcmp(op1, "LIST") == 0 || strcmp(op1, "PRINT") == 0 || strcmp(op1, "INSERT") == 0 || strcmp(op1, "SORT") == 0 || strcmp(op1, "EXIT") == 0)
	{
		printf("error\n");
		return;
	}
	else
	{
		op2 = op + strlen(op1) + 2;

		op2[strlen(op2) - 1] = '\0';


		pNew = (NODE*)malloc(sizeof(NODE));
		strcpy(pNew->name, op1);
		while (op2[i] != '\0')
		{
			if (i == 0)
			{
				pNew->value[j] = atoi(op2);
				j++;
			}
			else if (op2[i - 1] == ' '&&op2[i] != ' ')
			{
				pNew->value[j] = atoi(op2 + i);
				j++;
			}
			i++;

		}
		if (j > 32)
		{
			printf("error\n");
			return;
		}
		pNew->value_number = j;
		pPre->link = pNew;
		pNew->link = tail;
		pPre = pPre->link;

		return;

	}

	free(op);
	free(op2);//이거 작동 제대로 되는지 확인하기

}

/*

	varname을 키보드로 받은 후 기존에 저장한 node의 variable name과 같은 것이 있다면 해당 node의 저장된 값을 정수 값들출력한다


	parameter:

	varname- input의 뒷부분, print해야하는 list의 이름을 나타낸다.
	target- 초기값이 head이며 link를 통해 tail까지 이동하는 node.
	node들의 variable name중 varname과 일치하는 것이 있는지 확인한다.



	return value:NONE
*/
void PRINT()
{
	char varname[31];
	scanf("%s", varname);

	NODE* target = head;
	while (target != NULL)
	{
		if (strcmp(varname, target->name) == 0)
		{
			if (target->value_number == 0)
			{
				printf("empty\n");
				return;
			}
			else
			{
				for (int i = 0; i < target->value_number; i++)
				{
					printf("%d ", target->value[i]);

				}
				printf("\n");
				return;
			}

		}
		target = target->link;
	}
	printf("not found\n");
	return;
}

/*

	variable name과 index, integer values를 키보드로 받은 후, variable name이 일치하는 노드의 index에
	키보드로 받은 정수 값들을 끼워넣는다.

	parameter:

	target- 초기값은 head이며 tail까지 이동하는 노드. target의 변수 이름과 varname이 일치하는 노드가 있는지
	확인한다.
	index- 정수값들을 어느 위치에 삽입해야하는지 나타내는 값.
	plus_number- 추가된 정수값들의 개수
	plus_value- 추가된 정수값들의 integer array
	varname- 정수값들을 추가해야할 노드의 이름
	index_value- 키보드로 받은 추가해야할 정수값들,character array이다.
	i- 반복문으로 index_value의 정수값들을 확인할때 index_value의 index(parameter index와 다름)을 나타내는 것


	return value: NONE
*/
void INSERT()
{
	NODE* target = head;
	int index = 0, plus_number = 0, i = 0, plus_value[32];
	char varname[31], index_value[128];
	scanf("%s", varname);

	while (target != NULL)
	{
		if (strcmp(varname, target->name) == 0)
		{
			scanf("%d ", &index);
			if (index > target->value_number || index < 0)
			{
				fgets(index_value, sizeof(index_value), stdin);
				printf("error\n");
				return;
			}
			else
			{
				fgets(index_value, sizeof(index_value), stdin);
				index_value[strlen(index_value) - 1] = '\0';




				while (index_value[i] != '\0')
				{
					if (i == 0)
					{
						plus_value[plus_number] = atoi(index_value);
						plus_number++;
					}
					else if (index_value[i - 1] == ' '&&index_value[i] != ' ')
					{
						plus_value[plus_number] = atoi(index_value + i);
						plus_number++;
					}
					i++;
				}
				if (plus_number + target->value_number > 32)
				{
					printf("error\n");
					return;
				}
				else
				{
					for (int j = 0; j < target->value_number - index; j++)
					{
						target->value[target->value_number - j - 1 + plus_number] = target->value[target->value_number - j - 1];
					}
					for (int j = 0; j < plus_number; j++)
					{
						target->value[j + index] = plus_value[j];
					}
					target->value_number = target->value_number + plus_number;
					return;
				}

			}
		}
		target = target->link;
	}
	fgets(index_value, sizeof(index_value), stdin);
	printf("not found\n");
	return;

}


/*

	NODE의 정수값을 오름차순 또는 내림차순으로 정렬한다.

	parameter:
	target-초기값은 head이며 tail까지 이동하는 노드. target의 변수 이름과 varname이 일치하는 노드가 있는지
	확인한다.
	varname-정수값들을 정렬해야할 노드의 이름
	flag- 1이면 오름차순,-1이면 내림차순으로 정렬한다.(그 외의 값일 경우"error\n"을 출력)
	temp- NODE에 저장된 integer values를 정렬할때 임시로 값을 저장하는 변수


	return value: NONE
*/


void SORT()
{
	NODE* target = head;
	char varname[31];
	int flag = 0, temp;
	scanf("%s", varname);
	scanf("%d", &flag);
	if (flag != 1 && flag != -1)
	{
		printf("error\n");
		return;
	}
	while (target != NULL)
	{
		if (strcmp(target->name, varname) == 0)
		{
			if (flag == 1)
			{
				for (int i = 0; i < target->value_number; i++)
				{
					for (int j = i; j < target->value_number; j++)
					{
						if (target->value[i] > target->value[j])
						{
							temp = target->value[i];
							target->value[i] = target->value[j];
							target->value[j] = temp;

						}
					}
				}
				return;
			}
			else
			{
				for (int i = 0; i < target->value_number; i++)
				{
					for (int j = i; j < target->value_number; j++)
					{
						if (target->value[i] < target->value[j])
						{
							temp = target->value[i];
							target->value[i] = target->value[j];
							target->value[j] = temp;

						}
					}
				}
				return;
			}
		}
		target = target->link;
	}
	printf("not found\n");
	return;



}