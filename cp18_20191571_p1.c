#include <stdio.h>

union rope {
	unsigned long long ll[1];
	unsigned int i[2];
	unsigned short s[4];
	unsigned char c[8];
};

typedef enum {
	ROPE_C = 1, ROPE_S = 2, ROPE_I = 4, ROPE_LL = 8
}rope_type;

void print_rope(union rope r, rope_type t, int idx) {
	switch (t) {
	case ROPE_C:
		printf("=%02X=", r.c[idx]);
		break;
	case ROPE_S:
		printf("=%04X=", r.s[idx]);
		break;
	case ROPE_I:
		printf("=%08X=", r.i[idx]);
		break;
	case ROPE_LL:
		printf("=%016llX=", r.ll[idx]);
		break;
	default:
		printf("\n");
	}
}
int main()
{
	union rope r = { 0x0123456789ABCDEF }; 

	int n = 0, num[8], z = 0, p = 0,q=0;
	for (int i = 0; i < 8; i++)
	{
		num[i] = 1;
	}


	for (int i = 7; i >= 0; i--)
	{
		print_rope(r, 1, i);
	}

	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		if (n == 1)
		{
			p = 0;
			if(z!=8)
				z++;
			for (int i = 7; i >= z; i--)
			{
				if (num[i] == num[i - 1] && p == 0)
				{
					num[i] = num[i] * 2;


					p = 1;

					for (int j = i - 1; j >= z; j--)
					{
						num[j] = num[j - 1];
					}
					if (num[i] == ROPE_LL)
						print_rope(r, num[i], 0);
					if (num[i] == ROPE_I)
						print_rope(r, num[i], i - 6);
					if (num[i] == ROPE_S)
					{
						if (num[7]==4) 
						{
							print_rope(r, num[i], i - 5);
						}
						else
						{
						
							print_rope(r, num[i], i - 4);
						}
					}
				}
				else
				{
					for (int j = 7; j >= i; j--)
					{
						q = q + num[j];
					}
					if (num[i] != 1 && num[i] != 8)
					{
						if(num[7]==4&&num[i]==2)
							print_rope(r, num[i], i - num[i] - 3);
						else
						print_rope(r, num[i], i - num[i] - 2);
					}
					else if (num[i] == 1 )
						print_rope(r, num[i], 8-q);
					else
						print_rope(r, num[i], 0);
					q = 0;
				}
				
			}
		
			if (z == 8)
			{
				print_rope(r, 8, 0);
			}
		
		}
	}



	return 0;
}

