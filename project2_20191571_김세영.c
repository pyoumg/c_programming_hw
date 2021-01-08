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
	op1�� Ű����� ���� �� op1(input�� �� �պκ�)�� command(LIST,INSERT,PRINT,EXIT,SORT)�� ���
	���� command�� �´� �Լ��� �����ϰ�(EXIT�� ��� ���α׷� ����), �׷��� ���� ��� "error\n"�� ����Ѵ�.

	parameter:
	op1- input�� �� �պκ�


	return value:0(���α׷� ����)
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
	���� �̸��� ���������� Ű����� ���� ��, NODE�� �����Ѵ�.

	parameter:

	op- "LIST"�� ������ input�� �޺κ�
	op1- input�� �߰� �κ� (variable name)
	op2- input�� �޺κ�(integer values)
	i- integer values�� character array���� integer array�� ��ȯ�Ҷ� �ݺ����� �����ϴµ�, �̶� 0���� strlen(op)-1���� array ���� Ȯ���Ҷ� ����ϴ� ����
	j- ���������� ����

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
	free(op2);//�̰� �۵� ����� �Ǵ��� Ȯ���ϱ�

}

/*

	varname�� Ű����� ���� �� ������ ������ node�� variable name�� ���� ���� �ִٸ� �ش� node�� ����� ���� ���� ��������Ѵ�


	parameter:

	varname- input�� �޺κ�, print�ؾ��ϴ� list�� �̸��� ��Ÿ����.
	target- �ʱⰪ�� head�̸� link�� ���� tail���� �̵��ϴ� node.
	node���� variable name�� varname�� ��ġ�ϴ� ���� �ִ��� Ȯ���Ѵ�.



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

	variable name�� index, integer values�� Ű����� ���� ��, variable name�� ��ġ�ϴ� ����� index��
	Ű����� ���� ���� ������ �����ִ´�.

	parameter:

	target- �ʱⰪ�� head�̸� tail���� �̵��ϴ� ���. target�� ���� �̸��� varname�� ��ġ�ϴ� ��尡 �ִ���
	Ȯ���Ѵ�.
	index- ���������� ��� ��ġ�� �����ؾ��ϴ��� ��Ÿ���� ��.
	plus_number- �߰��� ���������� ����
	plus_value- �߰��� ���������� integer array
	varname- ���������� �߰��ؾ��� ����� �̸�
	index_value- Ű����� ���� �߰��ؾ��� ��������,character array�̴�.
	i- �ݺ������� index_value�� ���������� Ȯ���Ҷ� index_value�� index(parameter index�� �ٸ�)�� ��Ÿ���� ��


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

	NODE�� �������� �������� �Ǵ� ������������ �����Ѵ�.

	parameter:
	target-�ʱⰪ�� head�̸� tail���� �̵��ϴ� ���. target�� ���� �̸��� varname�� ��ġ�ϴ� ��尡 �ִ���
	Ȯ���Ѵ�.
	varname-���������� �����ؾ��� ����� �̸�
	flag- 1�̸� ��������,-1�̸� ������������ �����Ѵ�.(�� ���� ���� ���"error\n"�� ���)
	temp- NODE�� ����� integer values�� �����Ҷ� �ӽ÷� ���� �����ϴ� ����


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