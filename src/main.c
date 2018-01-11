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
    bool BOT = false;
    if (argc > 3) {
        printf(ANSI_BLUE "Usage: %s n [0/1:BOT]\n" ANSI_RESET "n: Dimension of the Board\n", argv[0]);
        return EXIT_FAILURE;
    }

    int N = argc > 1 ? atoi(argv[1]) : DIM_MIN;
    if (N < DIM_MIN || N > DIM_MAX) {
        printf(ANSI_RED "Fatal Error: Board dimension - Out of range\n" ANSI_RESET "Range: [%d, %d]\n",
                DIM_MIN, DIM_MAX);
        return EXIT_FAILURE;
    }

    int human;
    if (argc == 3) {
        BOT = true;
        human = atoi(argv[2]) == 0;
        srand(time(NULL));
    }

    int result = 0, pos, player = 0;
    const char Tic[] = {'X', 'O'};
    char Board[N * N];

    init(N, Board);
    greet();
    while (show(N, Board), ! result) {
        printf("\nFor Player(\'%c\'):\n", Tic[player]);
        do {
            if (BOT && (player == human)) {
                pos = moveAI(N, Board);
            } else {
                printf("Enter Position: "), fflush(stdout);
                scand(&pos);
                pos--;
            }
        } while ((pos < 0 || pos >= N * N || Board[pos] != '\0') &&
                printf(ANSI_YELLOW "Error: Invalid position.\n" ANSI_RESET));
        Board[pos] = Tic[player], player = ! player;
        newState(N, Board);
        result = check(N, Board);
    }

    if (result == 1 || result == 2) {
        printf(ANSI_GREEN "\nCongrats Player(\'%c\') wins\n" ANSI_RESET, Tic[result - 1]);
    } else {
        printf(ANSI_CYAN "\nMatch Tie !!!!!\n" ANSI_RESET);
    }
    setResult(N, result);

    return EXIT_SUCCESS;
}
