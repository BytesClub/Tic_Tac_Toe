/*
 * TIC_TAC_TOE
 *
 * GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
 * Copyright (C) BytesClub 2017, MIT
 *
 * color.h
 */

#define _XOPEN_SOURCE 500

#ifndef __color_h
#define __color_h

#define COLOR(X) #X

#define ANSI_RESET      COLOR(\033[0m)
#define ANSI_BOLD       COLOR(\033[1m)
#define ANSI_ITALIC     COLOR(\033[3m)
#define ANSI_UNDERLINE  COLOR(\033[4m)

#define ANSI_BLACK      COLOR(\033[30m)
#define ANSI_RED        COLOR(\033[31m)
#define ANSI_GREEN      COLOR(\033[32m)
#define ANSI_YELLOW     COLOR(\033[33m)
#define ANSI_BLUE       COLOR(\033[34m)
#define ANSI_MAGENTA    COLOR(\033[35m)
#define ANSI_CYAN       COLOR(\033[36m)
#define ANSI_WHITE      COLOR(\033[37m)

#endif
