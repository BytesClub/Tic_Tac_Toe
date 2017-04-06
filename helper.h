/*
 * TIC_TAC_TOE
 *
 * GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
 * Copyright (C) BytesClub 2017, MIT 
 *
 * helper.c
 */

#define _XOPEN_SOURCE 500

#ifndef __helper_h
#define __helper_h

#ifndef __stdio_h
#include <stdio.h>
#endif
#ifndef __stdlib_h
#include <stdlib.h>
#endif
#ifndef __unistd_h
#include <unistd.h>
#endif

/*
 * Minimum and Maximum Dimension
 */
#define DIM_MIN 3
#define DIM_MAX 9

/*
 * Initialization of the Board
 */
void init(int, char*);

/*
 * Prints a Welcome Message
 */
void greet(void);

/*
 * Loads the Modified Board
 */
void show(int, char*);

/*
 * Clear the console before printing the Board
 */
void clear(void);

/*
 * Checks if a user wins
 * Returns 1 if X wins
 * Returns 2 if O wins
 * Returns -1 if draw
 * Returns 0 otherwise
 */
int check(int, char*);

#endif