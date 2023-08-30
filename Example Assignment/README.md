<h1 align="center">Example Assignment</h1>

Your task for this assignment is to design, code (in C89 version of C) and test a program. In
summary, your program will:

* Able to create dynamically-allocated 2D char array to make 

* simple ASCII-based game.

* Receive user input to control the game.

* Utilize pre-written random number generator and terminal behavior configuration for the game.

* Write a proper makefile. Without the makefile, we will assume it cannot be compiled and it will negatively affect your mark.

## Task

You will implement a simple game that you can play on Linux terminal. 
The executable must be called **game** and it should accept **two** command line arguments in the following format

```bash
./game <map_row> <map_col>
```

both `map_row` and `map_col` must be even and greater than or equal to 5. Not facing these criteria must prompt appropriate error messages. Keep in mind you cannot use `exit()` nor multi returns and should find appropriate ways.

You must use `malloc()` when creating arrays with arbitrary sizes. Also, keep in mind to use `free()` to avoid any memory leaks. Use **valgrind** to test your program.

Basic functionalities of the game should include the following:

* player "P" and goal "G" must spawn in randomly, within bounds and not on each other.

* User must be able to move the player "P" within bounds using 'w', 'a', 's' and 'd'.

* At each player movement a random floor tile must break "X" and should update the map.

* A broken floor "X" cannot spawn on player "P" or goal "G" and a player cannot move towards a broken floor.