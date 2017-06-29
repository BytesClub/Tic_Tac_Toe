/*
 * TIC_TAC_TOE
 *
 * GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
 * Copyright (C) BytesClub 2017, MIT
 *
 * main.c
 */

#ifndef __helper_h
#include <helper.h>
#endif

int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf(ANSI_BLUE "Usage: %s n\n" ANSI_RESET "n: Dimension of the Board\n", argv[0]);
		return 1;
	}

	int N = atoi(argv[1]);
	if (N < DIM_MIN || N > DIM_MAX) {
		printf("Fatal Error: Board dimension - Out of range\nRange: [%d, %d]\n",
		        DIM_MIN, DIM_MAX);
		return 1;
	}

	int result = 0, pos, player = 0;
	const char Tic[] = {'X', 'O'};
	char Board[N * N];

	init(N, Board);
	greet();

	while (show(N, Board), !result) {
		do {
			printf("\nFor Player(\'%c\'):\n", Tic[player]);
			printf("Enter Position: "); 
			assert(scanf("%d", &pos) == 1);
			fflush(stdin), pos--;
		} while ((pos < 0 || pos >= N * N || Board[pos] != '\0') &&
		          printf(ANSI_CYAN "Error: Invalid position.\n" ANSI_RESET));
		Board[pos] = Tic[player], player = !player;
		result = check(N, Board);
	}

	if(result == 1 || result == 2) {
		printf(ANSI_GREEN "\nCongrats Player(\'%c\') wins\n" ANSI_RESET, Tic[result - 1]);
	} else {
		printf( ANSI_CYAN"\nMatch Tie !!!!!\n" ANSI_RESET);
	}

	return 0;
}
