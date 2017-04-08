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
	
	int result = 0, pos, player = 0;
	const char Tic[] = {'X', 'O'};
	char Board[N * N];
	
	init(N, Board);
	greet();
	
	while (clear(), show(N, Board), !result)	{
		do {
			printf("\nPlayer %d: Enter Postion: ", player + 1);
			scanf("%d",&pos);
			pos--;
		}while ((pos < 0 || pos >= N * N || Board[pos] != '\0') 
			&& printf("Error: Invalid position.\n"));
		Board[pos] = Tic[player], player = !player;
		result = check(N, Board);
	}

	if(result == 1) {
		printf("\nCongrats Player1 ('X') wins\n");
	} else if(result == 2) {
		printf("\nCongrats Player2 ('O') wins\n");
	} else {
		printf("\nMatch Tie !!!!!\n");
	}

	return 0;
}
