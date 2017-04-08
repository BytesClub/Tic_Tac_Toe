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
		printf("Usage: %s n\nn: Dimension of the Board\n", argv[0]);
		return 1;
	}
	
	int N = atoi(argv[1]);
	if (N < DIM_MIN || N > DIM_MAX) {
		printf("Fatal Error: Board dimension - Out of range\nRange: [%d, %d]\n", DIM_MIN, DIM_MAX);
		return 1;
	}
	
	int result = 0, row;
	char Board[N * N];
	
	init(N, Board);
	greet();
	
	while (!result)	{
		clear();
 		show(N, Board);
		
		printf("\nPlayer 1: Enter Postion: ");
		row = getchar();
		row = row-'1';
		Board[(row/3) * N + row%3]='X';
		show(N,Board);

		printf("\nPlayer 2: Enter Postion: ");
		row = getchar();
		row = row-'1';
		Board[(row/3) * N + row%3]='O';

		result = check(N, Board);
		/*
			TODO: The Board will be shown after each move by either user
		*/
	}

	if(result == 1) {
		printf("Congrats Player1 ('X') wins\n");
	} else if(result == 2) {
		printf("Congrats Player2 ('O') wins\n");
	} else {
		printf("Match Tie !!!!!\n");
	}

	return 0;
}
