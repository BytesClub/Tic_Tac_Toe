#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char fs(int p1, int p2)
{
	if(p1 == 1)
		return 'X';
	else if(p2 == 1)
		return 'O';
	else
		return ' ';

}

void human_vs_human()
{
	int i,j,turn=1,n,square=0,k,c;
	char *s;
	bool res;
	printf("Enter the no. of rows (or columns) (between 3 and 9 - both inclusive): ");
	do
	{
		error_human_1:
		k=0;
		free(s);
		s=malloc(1);
		do
    	{
    	    c = getchar();
    	    s[k++] = c;
    	    s = realloc(s, k+1);
    	}while(c != '\n' && c != EOF);
    	s[k] = '\0';
    	if(strlen(s) > 2)
    	{
    		printf("Wrong input.. Enter again...\n");
    		goto error_human_1;
    	}
    	else if(!(isdigit(s[0])))
    	{
    		printf("Wrong input.. Enter again...\n");
    		goto error_human_1;
    	}
		else
		{
			n=(int)s[0]-'0';
			if(n<3 || n>9)
			{
				printf("Wrong input.. Enter again...\n");
				goto error_human_1;
			}
		}
	}while(n<3 || n>9);
	int *p1=(int*)calloc(n*n,sizeof(int));
	int *p2=(int*)calloc(n*n,sizeof(int));
	int *test=(int*)calloc(n*n,sizeof(int));
	while(1)
	{
		printf("Turn of player %d\n",turn);
		printf(" ");
		for(i=0;i<n;i++)
			printf(" %d",i);
		printf("\n");
		printf("0 %c",fs(p1[0],p2[0]));
		for(i=1;i<n;i++)
			printf("|%c",fs(p1[i],p2[i]));
		printf("\n");
		for(i=1;i<n;i++)
		{
			printf(" ");
			for(j=0;j<n;j++)
				printf("--");
			printf("-\n");
			printf("%d %c",i,fs(p1[i*n],p2[i*n]));
			for(j=1;j<n;j++)
				printf("|%c",fs(p1[i*n + j],p2[i*n + j]));
			printf("\n");
		}
		do
		{
			enter_again:
			printf("Enter the row no. for your move (0 to %d - both inclusive)\n",n-1);
			error_human_2:
			k=0;
			free(s);
			s=malloc(1);
			do
	    	{
	    	    c = getchar();
	    	    s[k++] = c;
	    	    s = realloc(s, k+1);
	    	}while(c != '\n' && c != EOF);
	    	s[k] = '\0';
	    	if(strlen(s) > 2)
	    	{
	    		printf("Wrong input.. Enter again...\n");
	    		goto error_human_2;
	    	}
	    	else if(!(isdigit(s[0])))
	    	{
	    		printf("Wrong input.. Enter again...\n");
	    		goto error_human_2;
	    	}
			else
			{
				i=(int)s[0]-'0';
				if(i<0 || i>=n)
				{
					printf("Wrong input.. Enter again...\n");
					goto error_human_2;
				}
			}
			printf("Enter the column no. for your move (0 to %d - both inclusive)\n",n-1);
			error_human_3:
			k=0;
			free(s);
			s=malloc(1);
			do
	    	{
	    	    c = getchar();
	    	    s[k++] = c;
	    	    s = realloc(s, k+1);
	    	}while(c != '\n' && c != EOF);
	    	s[k] = '\0';
	    	if(strlen(s) > 2)
	    	{
	    		printf("Wrong input.. Enter again...\n");
	    		goto error_human_3;
	    	}
	    	else if(!(isdigit(s[0])))
	    	{
	    		printf("Wrong input.. Enter again...\n");
	    		goto error_human_3;
	    	}
			else
			{
				j=(int)s[0]-'0';
				if(j<0 || j>=n)
				{
					printf("Wrong input.. Enter again...\n");
					goto error_human_3;
				}
			}
			if(p1[i*n + j]==1 || p2[i*n + j]==1)
			{
				printf("Position is already occupied.. Enter again...\n");
				goto enter_again;
			}
			else
			{
				if(turn == 1)
					p1[i*n + j] = 1;
				else
					p2[i*n + j] = 1;
				break;
			}
		}
		while(1);
		if(turn == 1)
			for(i=0;i < n*n;i++)
				test[i] = p1[i];
		else
			for(i=0;i < n*n;i++)
				test[i] = p2[i];
		//first case: a row
		for(i=0;i<n;i++)
		{
			res=true;
			for(j=0;j<n;j++)
			{
				res = res && (test[i*n + j]==1);
				if(!res)
					break;
			}
			if(j==n)
				goto game_complete;
		}
		//second case: a column
		for(j=0;j<n;j++)
		{
			res=true;
			for(i=0;i<n;i++)
			{
				res = res && (test[i*n + j]==1);
				if(!res)
					break;
			}
			if(i==n)
				goto game_complete;
		}
		//third case: left-top to right-bottom diagonal
		res=true;
		for(i=0;i < n*n;i = i+n+1)
		{
			res = res && (test[i]==1);
			if(!res)
				break;
		}
		if(i == n*(n+1))
			goto game_complete;
		//fourth case: right-top to left-bottom diagonal
		res=true;
		for(i=n-1;i < n*n;i = i+n-1)
		{
			res = res && (test[i]==1);
			if(!res)
				break;
		}
		square++;
		if(i == (n*n)-1)
			goto game_complete;
		else if(square == n*n)
			goto game_draw;
		turn = 3 - turn;
	}
	game_complete:
	printf(" ");
	for(i=0;i<n;i++)
		printf(" %d",i);
	printf("\n");
	printf("0 %c",fs(p1[0],p2[0]));
	for(i=1;i<n;i++)
		printf("|%c",fs(p1[i],p2[i]));
	printf("\n");
	for(i=1;i<n;i++)
	{
		printf(" ");
		for(j=0;j<n;j++)
			printf("--");
		printf("-\n");
		printf("%d %c",i,fs(p1[i*n],p2[i*n]));
		for(j=1;j<n;j++)
			printf("|%c",fs(p1[i*n + j],p2[i*n + j]));
		printf("\n");
	}
	printf("Game over..\n");
	if(turn == 1)
		printf("Player 1 have won the match!!!\n");
	else
		printf("Player 2 have won the match!!!\n");
	return;

	game_draw:
	printf(" ");
	for(i=0;i<n;i++)
		printf(" %d",i);
	printf("\n");
	printf("0 %c",fs(p1[0],p2[0]));
	for(i=1;i<n;i++)
		printf("|%c",fs(p1[i],p2[i]));
	printf("\n");
	for(i=1;i<n;i++)
	{
		printf(" ");
		for(j=0;j<n;j++)
			printf("--");
		printf("-\n");
		printf("%d %c",i,fs(p1[i*n],p2[i*n]));
		for(j=1;j<n;j++)
			printf("|%c",fs(p1[i*n + j],p2[i*n + j]));
		printf("\n");
	}
	printf("Well, it's a draw!!!\n");
}

int main()
{
	int option,c,i=0;
	char *s = malloc(1);
	printf("Welcome to the world of Tic-Tac-Toe...\n\n");
	do
	{
		printf("Select:\n");
		printf(" 2 for 2-player (HUMAN vs HUMAN)\n");
		printf(" or 0 to exit\n");
		enter_again_main: //in case of an invalid input
		free(s); s=malloc(1); i=0;
		do
    	{
    	    c = getchar();
    	    s[i++] = c;
    	    s = realloc(s, i+1);
    	}while(c != '\n' && c != EOF);
    	s[i] = '\0';
    	if(strlen(s) > 2)
    		goto default_error;
    	else if(!(isdigit(s[0])))
    		goto default_error;
		else
		{
			option=(int)s[0]-'0';
			switch(option)
			{
				/*case 1:human_vs_ai();
				       break;*/
				case 2:human_vs_human();
				       break;
				case 0:printf("Hope to see you again soon..\n");
				       break;
				default:default_error:
						printf("Wrong input.. Enter again...\n");
						goto enter_again_main;
			}
		}
	}while(option);
	printf("\n");
	system("pause");
	return 0;
}