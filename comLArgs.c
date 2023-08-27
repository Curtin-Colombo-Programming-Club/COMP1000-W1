#include <stdio.h>

int main(int argc, char**argv) {
    /* 
        argc - argument count
        argv - arguments/argument array
    */
   int i;

    /* printing all the arguments to terminal */
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    
    return 0;
}