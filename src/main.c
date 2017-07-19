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
		printf(ANSI_RED "Fatal Error: Board dimension - Out of range\n" ANSI_RESET "Range: [%d, %d]\n",
		        DIM_MIN, DIM_MAX);
		return 1;
	}

	int result = 0, pos, player = 0,i,avoid_error=0;
	const char Tic[] = {'X', 'O'};
	char Board[N * N],c;
	char* s;

	init(N, Board);
	greet();

	while (show(N, Board), !result) {
		do {
			printf("\nFor Player(\'%c\'):\n", Tic[player]);
			printf("Enter Position (non-digit characters not allowed.. not even white spaces...): ");
			do {
				i = 0;
				s = malloc(1);
				do {
					c = getchar();
					s[i++] = c;
					s = realloc(s, i+1);
				} while (c != '\n' && c != EOF);
				s[i] = '\0';
				if (strlen(s) < 2 || (strlen(s) == 2 && !(Isdigit(s[0]))) || (strlen(s) == 3 && (!(Isdigit(s[0])) || !(Isdigit(s[1])))) || strlen(s) > 3) {
					if (avoid_error) {
						printf("Wrong input.. Enter again...\n");
					} else {
						avoid_error = 1;
					}
					free(s);
				} else {
					if (strlen(s) == 2) {
						pos = (int)s[0]-'0';
					} else {
						pos = ((int)s[0]-'0')*10 + ((int)s[1]-'0');
					}
					break;
				}
			} while (strlen(s) < 2 || (strlen(s) == 2 && !(Isdigit(s[0]))) || (strlen(s) == 3 && (!(Isdigit(s[0])) || !(Isdigit(s[1])))) || strlen(s) > 3);
			pos--;
		} while ((pos < 0 || pos >= N * N || Board[pos] != '\0') &&
		          printf(ANSI_YELLOW "Error: Invalid position.\n" ANSI_RESET));
		Board[pos] = Tic[player], player = !player;
		result = check(N, Board);
	}

	if(result == 1 || result == 2) {
		printf(ANSI_GREEN "\nCongrats Player(\'%c\') wins\n" ANSI_RESET, Tic[result - 1]);
	} else {
		printf(ANSI_CYAN "\nMatch Tie !!!!!\n" ANSI_RESET);
	}

	return 0;
}
