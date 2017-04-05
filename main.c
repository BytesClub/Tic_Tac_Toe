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
	if (argc != 2) {
		printf("Usage: %s n\n", argv[0]);
		return 1;
	}
	
	int N = atoi(argv[1]);
	if (N < DIM_MIN || N > DIM_MAX) {
		printf("Fatal Error: Board dimension - Out of range\nRange: [%d, %d]\n", DIM_MIN, DIM_MAX);
		return 1;
	}
	
	int result = 0, row, col;
	char ARR[N][N];
	
	init(N, (char*)ARR);
	greet();
	
	while (!result)	{
		printf("\nPlayer 1: Enter Postion:\nRow Number: ");
		row = getchar();
		printf("\nColumn Number: ");
		col = getchar();
		ARR[row][col]='X';

		printf("\nPlayer 2: Enter Postion:\nRow Number: ");
		row = getchar();
		printf("\nColumn Number: ");
		col = getchar();
		ARR[row][col]='O';

		clear();
 		show(N, (char*)&N);
		result = check(N, (char*)ARR);
		/*
			TODO: The Board will be shown after each move by either user
		*/
	}

	if(result == 1){
		printf("Congrats Player1 ('X') wins\n");
	} else if(result == 2){
		printf("Congrats Player2 ('O') wins\n");
	} else{
		printf("Match Tie !!!!!\n");
	}

	return 0;
}
