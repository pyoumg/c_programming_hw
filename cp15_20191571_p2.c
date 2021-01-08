#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _waterContainer
{
	double water;
}waterContainer;

void addWater(waterContainer*, double water);
void combineWater(waterContainer*, waterContainer*);
void removeWater(waterContainer*);


int main()
{
	waterContainer* cup1=(waterContainer*)malloc(sizeof(waterContainer));
	waterContainer* cup2=(waterContainer*)malloc(sizeof(waterContainer));
	cup1->water = 0;
	cup2->water = 0;
	int n, n1;
	double n2;
	while (1)
	{
		printf("choose operator\n");
		printf("0: quit 1: addWater, 2: removeWater, 3: combineWater\n");
		scanf("%d", &n);

		switch (n)
		{
		case 0:
			printf("cup1: %.2lf, cup2: %.2lf\n", cup1->water, cup2->water);
			return 0;
			break;
		case 1:
			printf("choose cup : ");
			scanf("%d", &n1);
			printf("input water: ");
			scanf("%lf", &n2);
			if (n1 == 1)
			{
				addWater(cup1, n2);

			}
			else
			{
				addWater(cup2, n2);
			}

			break;
		case 2:
			printf("choose cup : ");
			scanf("%d", &n1);
			if (n1 == 1)
				removeWater(cup1);
			else
				removeWater(cup2);
			break;
		case 3:
			combineWater(cup1, cup2);

		}
	}
	free(cup1);
	free(cup2);
		return 0;
	}

void addWater(waterContainer* cup, double water)
	{
		cup->water = water+ cup->water;
		return;

	}
void combineWater(waterContainer* c1, waterContainer* c2)
	{
	c1->water = c1->water + c2->water;
	c2->water=0;
	return;
	}
void removeWater(waterContainer* cup)
	{
	cup->water = 0;
	return;
	}
