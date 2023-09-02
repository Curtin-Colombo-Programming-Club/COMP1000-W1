##
 # File: Makefile
 # File Created: Tuesday, 31 Aug 2023 7:12:45 am
 # Author: Roman Fredrick
 # -----
 # Purpose: A makefile to compile the MulFile prefixed c files
##


# Makefile Variables
CC		 = gcc
EXEC	 = game
CFLAGS   = -Wall -ansi -pedantic
C        = main.c map.c terminal.c random.c
OBJ 	 = main.o map.o terminal.o random.o

# -> binary file
$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
	rm $(OBJ)

# -> object files
$(OBJ) : $(C)
	$(CC) $(CFLAGS) $(C) -c 

# - binary file and object files
clean:
	rm $(EXEC) $(OBJ)