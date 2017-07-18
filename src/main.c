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
		do
		{
			printf("\nFor Player(\'%c\'):\n", Tic[player]);
			printf("Enter Position (non-digit characters not allowed.. not even white spaces...): ");
			goto init__1;
			error_pos: //in case invalid input is given
			free(s);
			init__1:
			i=0;
			s=malloc(1);
			do
			{
				c = getchar();
				s[i++] = c;
				s = realloc(s,i+1);
			}while(c != '\n' && c != EOF);
			s[i] = '\0';
			switch(strlen(s))
			{
				case 2:if(!(isdigit(s[0])))
					{
						printf(ANSI_YELLOW "Wrong input.. Enter again...\n" ANSI_RESET);
						goto error_pos;
					}
					else
						pos=(int)s[0]-'0';
					break;
				case 3:if(!(isdigit(s[0])) || !(isdigit(s[1])))
					{
						printf(ANSI_YELLOW "Wrong input.. Enter again...\n" ANSI_RESET);
						goto error_pos;
					}
					else
						pos=((int)s[0]-'0')*10 + ((int)s[1]-'0');
					break;
				default:if(avoid_error)
						printf(ANSI_YELLOW "Position can't have more than two digits.. Enter again...\n" ANSI_RESET);
					if(avoid_error == 0) avoid_error = 1;
					goto error_pos;
			}
			pos--;
		}while ((pos < 0 || pos >= N * N || Board[pos] != '\0') &&
		          printf(ANSI_YELLOW "Error: Invalid position.\n" ANSI_RESET));
		Board[pos] = Tic[player], player = !player;
		result = check(N, Board);
	}

	if(result == 1 || result == 2) {
		printf(ANSI_GREEN "\nCongrats Player(\'%c\') wins\n" ANSI_RESET, Tic[result - 1]);
	} else {
		printf(ANSI_CYAN"\nMatch Tie !!!!!\n" ANSI_RESET);
	}

	return 0;
}
