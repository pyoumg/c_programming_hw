#include <stdio.h>
#include <stdlib.h>

int main()
		{
			char *ip1;
			int*ip2;
			int size=20;

			ip1=(char*)malloc(sizeof(char)*size);
			ip2=(int*)malloc(sizeof(int)*size);

			int N;
			scanf("%d\n",&N);
			for(int i=0;i<N;i++)
			{
				char line[128];
				fgets(line,128,stdin);
				int value;
				char key;
				sscanf(line,"%c%d",&key,&value);
				ip1[i]=key;
				ip2[i]=value;



			}




			int M;
			scanf("%d\n",&M);
			for(int i=0;i<M;i++)
			{
				char line[128];
				char key;
				fgets(line,128,stdin);
				sscanf(line,"%c",&key);
			
				for(int j=0;j<N;j++)
				{
					if(ip1[j]==key)
					{
						printf("%d\n",ip2[j]);
						break;

					}
					else if(j==N-1)
					{
							printf("Not Found\n");
					}

				}
			}

			free(ip1);
			free(ip2);


			return 0;

		}
