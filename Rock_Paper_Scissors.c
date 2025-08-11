#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int	choix;
	char *chose[] ={"paper","scissor","rock"};
	srand(time(NULL));
	int	Random = ( rand()	 % 3) + 1;
	do{
		printf("chose:\n1-for paper\n2-for scissor\n3-for rock\n:");
		scanf("%d", &choix);
	}while(choix != 1 && choix != 2 && choix != 3);
	printf("you chose %s \n",chose[choix - 1]);
	printf("the bot chose %s \n",chose[Random - 1]);
	if (choix == Random)
	{
		printf("Draw !\n");
		return 0;
	}
	if (choix == 1)
	{
		if (Random == 3)
			printf("you Won !\n");
		else
			printf("you lose !\n");
	}else if (choix == 2)
	{
		if (Random == 1)
			printf("you Won !\n");
		else
			printf("you lose !\n");
	}else if (choix == 3)
	{
		if (Random == 2)
			printf("you Won !\n");
		else
			printf("you lose !\n");
	}
	return 0;
}