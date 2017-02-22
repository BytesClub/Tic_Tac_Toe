/*
 * TIC_TAC_TOE
 *
 * GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
 * Copyright (C) BytesClub 2017, MIT 
 *
 * helpers.c
*/

#include "helpers.h"

void greet(void)
{
	clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

void init(int n, int*)
{
	// TODO
}

void show(int, int*)
{
	
}

void clear(void)
{
	printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

int check(int n, int* A)
{
	// TODO
	return 0;
}