/*
 * TIC_TAC_TOE
 *
 * GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
 * Copyright (C) BytesClub 2017, MIT 
 *
 * main.c
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	
	unsigned int n = atoi(argv[1]);
	int f = 0;
	
	greet();
	while(!f)
	{
		clear();
		show();
		/*
		 * TODO: Ask user for the position
		*/
		f = check()
	}
	
	/*
	 * TODO: Print if its a win or draw
	*/
	
	return 0;
}
