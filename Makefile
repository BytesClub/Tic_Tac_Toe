#
# Makefile
# 
# GitHub Repository: https://github.com/BytesClub/Tic_Tac_Toe
# Copyright (C) BytesClub 2017, MIT
#

# Define Compiler
CC = gcc

# Flags for Compiler
CFLAGS = -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow 

# Flags for Linker
LFLAGS = -pg

# Flags for Directories
DIR = -I$(INC)

# Executable
EXE = play

# Directories
SRC = src
INC = inc
BIN = bin

# Source and Object File(s)
SOURCE = $(wildcard $(SRC)/*.c)
OBJECT = $(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.c=.o)))

# Default Target
$(BIN)/$(EXE): $(OBJECT)
	$(CC) $^ -o $@

$(BIN)/%.o: $(SRC)/%.c
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(DIR) -c $< -o $@

# Help Option
help:
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"

# House-keeping
clean:
	rm -rf core $(EXE) bin/* *.o *.exe
