# COMP1000 ASSIGNMENT 1 WORKSHOP MATERIALS

This repo will include all the materials used in our workshop for COMP1000 Assignment 1 aided by the Programming Club of Curtin Colombo

<details>
    <summary><h2>0. Setup</h2></summary>
    <h3>i. Environment</h3>
    <p>
    To start you need an unix environment, and if you don't have one, you can create a virtual environment using <a href="https://www.vmware.com/products/workstation-player.html">VMware Workstation Player</a> or <a href="https://www.virtualbox.org/wiki/Downloads">VirtualBox</a>, Or else you can download <a href="https://learn.microsoft.com/en-us/windows/wsl/install">wsl</a>
    <p>
    <h3>ii. Installing requirements</h3>
    To follow along with this workshop, you need the following
    <ul>
        <li>git - to clone this repo</li>
        <li>gcc - for c compiling</li>
        <li>valgrind - to check for memory leaks</li>
    </ul>
    <p>
    Before anything we need to update and upgrade our unix environment using the following command
    </p>
   <br>
    ```bash
    sudo apt upgrade && apt update
    ```
</details>

## 1. Starter

As for starters, it's ideal to understand how the basics of **c** language work, hence we have made a starter.c to start this learning.

In **c** a file is made using the extension `.c` and in that file we would declare and initialize the function of type `int` of the name `main`, here is where we write the main program. The `main` function will return `0` to hint to the runtime that the execution was successful.

In the **starter.c** file we have declared a `main` function that will,

1. declare a variable(s) and initialize them.
2. print `"Hello World!"` to the terminal.
3. print an integer product.

(_refer to the starter.c file_).

> _The reason many newly created programs/scripts print "Hello, World!" is to give a friendly greeting to the world as they start their journey._

To run our **starter.c** file we need to first compile the file to a binary file. The process of doing it is as follows,

**To compile a single file**

```bash
gcc [cflags] "path\to\file.c" -o "output\dir\output"
```

_make sure to replace the names with the correct file names_

To compile a starter.c we need to use the following command

```bash
gcc -Wall -ansi -pedantic starter.c -o starter
```

> Wall - Enables all compiler's warning messages<br>
> ansi - This is equivalent to -std=c89, which hints to use C89 standards<br>
> pedantic - Generate warnings if code violates strict ISO C

## 2. Arrays

Going forward we need to understand what arrays are, and how to declare and initialize them.

**Definition**:
An array is a data structure, which can store a fixed-size collection of elements of the same data type.

The basic notation of declaring an array is as follows

```c
type arrayName[size];
```

> type - type of the array being declared<br>
> arrayName - the array variable name<br>
> size - size of the array

To get a value/element in an array we use indexing as follows

```c
arrayName[index]
```

> arrayName - the array variable name<br>
> index - positional value of the required element

> _It's commonly known that indexing starts from 0, and the reason for it is that this number represents the offset number from the array's memory address._

Refer to **arrays.c** file to see the examples of declaring and initializing arrays

**to compile array.c**

```bash
gcc -Wall -ansi -pedantic arrays.c -o arrays
```

**to execute**

```bash
./arrays
```

In the terminal DEBUG output, you'll be able to identify that intArray1 and charArray1 elements would be garbage values.

## 3. 2D Arrays

Similar to 1D arrays 2D arrays are a collection of arrays of the same array types.

Following are some examples of declaring and initializing 2D arrays

```c
/* int 2D arrays */
int intMatrix1[3][3];
int intMatrix2[3][3] = {{1, 2, 3}, {2 , 4, 6}, {1, 3, 5}};

/* char 2D arrays */
char charMatrix1[3][3];
char charMatrix2[3][3] = {"tic", "tac", "toe"};
```

## 4. Functions...

Functions are blocks of codes, that can take in parameter arguments and also return or change data after computation.

Following is the syntax of a function

```c
type functionName(/* optionally can declare varibales for paramtere args */)
{
    /* code */

    /* return data of type of the function except void */
}
```

> type - type of the function<br>
> functionName - name of the function

example

```c
/* declaration and initialization of the function mul */
int mul(int a, int b)
{
    int result = a * b;

    return result;
}

/* main */
int main()
{
    /* calling mul */
    mul(2, 3); /* -> 6 */

    return 0; /* successful */
}
```

When it comes to the function calling a function needs to be declared before/above the point it's called and also need to make sure you pass in the needed argument.

Refering to **functions1.c** file, we can see both `add` and `mul` functions are declared and initialized before being called in the `main`.

**to compile functions1.c**

```bash
gcc -Wall -ansi -pedantic functions1.c -o functions1
```

**to execute**

```bash
./functions1
```

Refering to **functions2.c** file, we can see both `add` and `mul` functions are declared before being called in the `main` but initialized afterwards. This also works since the compilation will know that a such function does exist and when initialized will update the declaration.

**to compile functions2.c**

```bash
gcc -Wall -ansi -pedantic functions2.c -o functions2
```

**to execute**

```bash
./functions2
```

## 5. Comman Line Arguments

As a part of Assignment 1, you need to be able to read command line arguments from your program.

_please refer to the comLArgs.c file_

In the comLArgs.c we have initialized the `main` function with 2 arguments, which are `argc` of type `int` and `argv` of type `char**`

> argc - argument count<br>
> argv - argument array (an array of char arrays)

Compile and run the program to see the command line arguments, and also pass in random arguments to test this.

**to compile comLArgs.c**

```bash
gcc -Wall -ansi -pedantic comLArgs.c -o comLArgs
```

**to execute**

```bash
./comLArgs
```

**example executions**

```bash
./comLArgs arg1 arg2 arg3
```

```bash
./comLArgs 1 2 3
```

> _Notice that the first argument from the output of `comLArgs` will always be the binary file name!_

## 6. The Great MALLOC Himself!

In general size of an array needs to be defined and be available at compilation time.

But in some cases, we need to create arrays with a size determined at run time, just like how we are required to in this Assignment.

This is where we use the function `malloc`, which will manually allocate memory for the size we pass in as bytes.

Following is the syntax and example of allocating memory<br>
syntax

```c
type * varName = malloc(sizeof(type)*n);
```

> type - type of data<br>
> varName - variable name<br>
> n - number of data values to be stored

example (1D array)

```c
int * intArray = malloc(sizeof(int) * 5) /* an int array of size of 5 */
```

Also, refer to **customArray.c** for more practical usages.

**to compile comLArgs.c**

```bash
gcc -Wall -ansi -pedantic customArray.c -o customArray
```

**to execute**

```bash
./customArray
```

> _Note that to use `malloc` function you need to include the `stdlib` header file and also following this function at the end of execution runtime you have to manually free the allocated memory_

## 7. Multiple Files?

When programming we tend to categorize our functions into different files, but when compiling we need to link them together.

Before compiling when building/programming our functions we would share these functions among the other files we have, so it's important to share the functions' information using header files and `#include`

A header file is simply a file holding its corresponding c file's function declarations and it's important you need to include this header file in its corresponding c file and other c files that would use the functions declared.

When using `#include`, normally to include a standard library file we would call it as follows for example `#include <stdio.h>` (stdio is a standard library file), but since we created our function files in our working dir, we need to call them as follows `#include "fileName.h"`.

Let us refer to the given example files, prefixed with "MulFile".

To compile them together, first, you need to create the object file using `-c` flag

syntax<br>
single file

```bash
gcc -Wall -ansi -pedantic fileName.c -c
```

multiple files

```bash
gcc -Wall -ansi -pedantic file1.c file2.c file3.c -c
```

Then you need to link all the object file files together

```bash
gcc file1.o file2.o file3.o -o outPut
```

**to compile MulFileMain.c, MulFileMath.c and MulFileStr.c**<br>
First

```bash
gcc -Wall -ansi -pedantic MulFileMain.c MulFileMath.c MulFileStr.c -c
```

Then

```bash
gcc -Wall -ansi -pedantic MulFileMain.o MulFileMath.o MulFileStr.o -o MulFile
```

**to execute**

```bash
./MulFile
```

## 8. MakeFile (ﾉ ◕ ヮ ◕)ﾉ\*:・ﾟ ✧

As you saw before making the object file and linking them all together was a lot of work, especially when it comes to recompiling after fixing errors.

To solve this problem we create a **MakeFile** (could be abbreviated as, makefile, Makefile) which contains the instructions to compile our files.

Refer to the **Makefile** that is provided which will compile all MulFile prefixed c files.

Use the following command to run the **Makefile**

```bash
make
```
