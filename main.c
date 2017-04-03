/*
 * TIC_TAC_TOE
 *
 * GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
 * Copyright (C) BytesClub 2017, MIT 
 *
 * main.c
 */

#include "helper.h"

int main(int argc, char* argv[])
{
	/*
	 * TODO: Validating input arguments
	 */
	if(argc != 2){
		printf("Usage: %s n\n", argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);
	int result= 0;
	char ARR[n][n];

	printf("%u", n);

	greet();
  while(!result)
	{
		clear();
                printf("\nPlayer 1: Enter Postion:\nRow Number: ");
                row=getchar();
                printf("\nColumn Number: ");
                col=getchar();
		ARR[row][col]='X';

                printf("\nPlayer 2: Enter Postion:\nRow Number: ");
                row=getchar();
                printf("\nColumn Number: ");
                col=getchar();
                ARR[row][col]='O';
                
 		show(n, &n);
		/*
		 * TODO: Ask user for the position
		 */

		result = check(n, ARR);
	}
	if(result==1){
		printf(" Congrats Player1 ('X') wins\n");
	}
	else if(result==2){
		printf("Congrats Player2 ('O') wins\n");
	}
	else{
		printf(" Match Tie !!!!!\n");
	}


	return 0;
}
