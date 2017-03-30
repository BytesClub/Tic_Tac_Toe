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
	int f = 0;

	printf("%u", n);

	greet();
	while(!f)
	{
		clear();
		show(n, &n);
		/*
		 * TODO: Ask user for the position
		 */
		f = check(n, &n);
	}

	/*
	 * TODO: Print if its a win or draw
	 */

	int result=f;
	if(result==1){
		printf(" Congrats 'X' wins\n");
	}
	else if(result==2){
		printf("Congrats 'O' wins\n");
	}
	else if(result==-1){
		printf(" GAME DRAWN!!!!!\n");
	}
	else {
		printf("!!! GAME incomplete!!!\n");
	}   	



	return 0;
}
