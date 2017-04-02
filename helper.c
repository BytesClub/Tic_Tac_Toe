/*
 * TIC_TAC_TOE
 *
 * GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
 * Copyright (C) BytesClub 2017, MIT 
 *
 * helper.c
 */

#include "helper.h"
char player1='X',player2='O';
int n;


void greet(void)
{
	clear();
	printf("WELCOME TO GAME OF TIC_TAC_TOE\n");
	sleep(5);
}

void init(int n, int* A)
{
	// TODO : Initialize the board.
}

static int val(int d)
{
	// TODO : Add Value against board
	return '\0';
}

void show(int n, int* A)
{
	for(int i = 0; i < n; i++){
		for(int j = 0; (j < n && (!j || putchar('|'))) || putchar('\n'); j++)
			printf(" %c ", val(A[i * n + j]));
		for(int j = 0; j < n || !putchar('\n'); j++)
			printf("----");
	}
}

void clear(void)
{
	printf("\033[2J");
	printf("\033[%d;%dH", 0, 0);
}

int check(int s , char (*C)[n])
{

	int row,column;
	// checking for row wise//
	for(row=0;row<s;row++)
	{
		char i=C[row][0];int flag=0;
		for(column=0;column<s;column++)
		{
			if(i==C[row][column])
				flag=1;
			else {
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			if(C[row][0]==player1)
				return 1;
			if(C[row][0]==player2)
				return 2;


		}
	}
	// checking for column wise//
	for(column=0;column<s;column++)
	{
		char i=C[0][column];int flag=0;
		for(row=0;row<s;row++)
		{
			if(i==C[row][column])
				flag=1;
			else {
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			if(C[0][column]==player1)
				return 1;

			if(C[0][column]==player2)
				return 2;


		}
	}
	//checking for diagonals//
	//major diagonal//
	char i=C[0][0];int flag=0;
	for(row=0,column=0;row<s,column<s;row++,column++)
	{
		if(i==C[row][column])
			flag=1;
		else {
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		if(C[0][0]==player1)
			return 1;

		if(C[0][0]==player2)
			return 2;

	}
	//Checking for minor diagonal//
	char j=C[0][s-1];int flag_1=0;
	for(row=0,column=s-1;row<s,column>=0;row++,column--)
	{
		if(j==C[row][column])
			flag_1=1;
		else {
			flag_1=0;
			break;
		}
	}
	if(flag_1==1)
	{
		if(C[0][s-1]==player1)
			return 1;

		if(C[0][s-1]==player2)
			return 2;

	}

	//condition of draw and incomplete game//
	int flag_2=0;
	for(row=0;row<s;row++)
	{
		for(column=0;column<s;column++)
		{
			if(C[row][column]==player1||C[row][column]==player2)
				flag_2=1;
			else 
			{
				flag_2=0;
				break;
			}
		}
	}
	if(flag_2==1)
		return 3;

	else
		return 0;


}
