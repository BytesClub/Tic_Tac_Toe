/*
 * TIC_TAC_TOE
 *
 * GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
 * Copyright (C) BytesClub 2017, MIT
 *
 * ai.c
 */

#ifndef __helper_h
#include <helper.h>
#endif

static char State[DIM_MAX * DIM_MAX][DIM_MAX * DIM_MAX];
static int k = 0;

int moveAI(int n, const char* Board)
{
    int space = n * n;
    int position;
    do {
        position = rand() % space;
    } while (Board[position]);
    return position;
}

void newState(int n, const char* Board)
{
    for (int i = 0, l = n * n; i < l; i++) {
        State[k][i] = Board[i] ? Board[i] : '-';
    }
    k++;
}

void setResult(int n, int result)
{
    FILE* log = fopen("log.txt", "a+");
    if (log == NULL) {
        return;
    }
    for (int i = 0; i < k; i++) {
        int l = n * n;
        fprintf(log, "%d ", l);
        for (int j = 0; j < l; j++) {
            fputc(State[i][j], log);
        }
        fprintf(log, " %d\n", result);
    }
    fclose(log);
}
