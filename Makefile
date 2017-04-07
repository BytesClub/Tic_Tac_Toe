#
# Makefile
# 
# GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
# Copyright (C) BytesClub 2017, MIT
#

# Define Compiler
CC = gcc

# Flags for Compiler
CFLAGS = -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow -I$(INC)

# Executable
EXE = play

SRC = src
INC = inc
BIN = bin

SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.c=.o)))

$(BIN)/$(EXE): $(OBJECT)
	$(CC) $^ -o $@

$(BIN)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

help:
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"

