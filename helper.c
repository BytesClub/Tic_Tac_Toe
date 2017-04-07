/*
 * TIC_TAC_TOE
 *
 * GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
 * Copyright (C) BytesClub 2017, MIT 
 *
 * helper.c
 */

#include "helper.h"

void greet(void)
{
	clear();
	printf("WELCOME TO GAME OF TIC_TAC_TOE\nCreated by: Bytes Club\n\n");
	sleep(5);
	clear();
}

void init(int n, char* A)
{
	for (int i = 0, l = n * n; i < l; i++)
		A[i] = '\0';
}

void show(int n, char* A)
{
	for (int i = !putchar('\n'); i < n; i++) {
		for (int j = 0; (j < n && (!j || putchar('|'))) || !putchar('\n'); j++)
			printf(" %c ", A[i * n + j]);
		for (int j = 0; !(i + 1 == n) && (j < n || !putchar('\n')); j++)
			printf("----");
	}
}

void clear(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH", 0, 0);
}

int check(int n, char* A)
{
	int row, col, flag = 0;
	// Row-wise checking
	for (row = 0; row < n; row++) {
		for (col = 1; col < n || !(flag = 1); col++)
			if (A[row * n + col] != A[row * n + col - 1])
				break;
		if (flag)
			return A[row * n + col - 1] == 'X' ? 1 : 2;
	}
	// Column-wise checking
	for (col = 0; col < n; col++){
		for (row = 1; row < n || !(flag = 1); row++)
			if (A[row * n + col] != A[row * n + col - 1])
				break;
		if (flag)
			return A[row * n + col - 1] == 'X' ? 1 : 2;
	}
	// Upper diagonal checking
	for (row = col = 0; row < n || !(flag = 1); row++, col++){
		if (A[row * n + col] != A[(row - 1) * n + col - 1])
			break;
		if (flag)
			return A[0] == 'X' ? 1 : 2;
	}
	// Lower diagonal checking
	for (row = col = n; row > 0 || !(flag = 1); --row, --col){
		if (A[row * n + col] != A[(row - 1) * n + col - 1])
			break;
		if (flag)
			return A[n - 1] == 'X' ? 1 : 2;
	}
	// Checking for empty position
	for (row = 0; row < n; row++){
		for (col = 0; col < n || !(flag = 1); col++)
			if (A[row * n + col] == '\0')
				break;
		if (flag)
			return -1;
	}
	// Match is on
	return 0;
}
