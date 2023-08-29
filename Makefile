##
 # File: Makefile
 # File Created: Tuesday, 29 Aug 2023 3:28:42 pm
 # Author: Roman Fredrick
 # -----
 # Purpose: A makefile to compile the MulFile prefixed c files
##


# Makefile Variables
CC		 = gcc
EXEC	 = MulFile
CFLAGS   = -Wall -ansi -pedantic
C        = MulFileMain.c MulFileMath.c MulFileStr.c
OBJ 	 = MulFileMain.o MulFileMath.o MulFileStr.o

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