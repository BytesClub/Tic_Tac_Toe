#
# Makefile
# 
# GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
# Copyright (C) BytesClub 2017, MIT
#

# Define Compiler
CC = gcc

# Flags for Compiler
CFLAGS = -ggdb -Werror -Wall

# Executable
EXE = a.out

# Header File(s)
HDRS = helpers.h

# Source File(s)
SRCS = main.c

# Object File(s)
OBJS = $(SRCS:.c=.o)

# Default Target
main: $(OBJS) $(HDRS) Makefile
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LIBS)

# Dependencies 
$(OBJS): $(HDRS) Makefile

# House-keeping
clean:
	rm -f core $(EXE) *.o *.exe
