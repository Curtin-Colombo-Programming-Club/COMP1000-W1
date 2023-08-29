#include <stdio.h>

/* declaration and initialization of the function add */
int add(int _a, int _b) {
    return _a + _b;
}

/* declaration and initialization of the function mul */
int mul(int _a, int _b) 
{
    return _a * _b;
}


int main()
{
    int a = 5, b = 7;

    printf("a + b = %d\n", add(a, b));

    printf("a * b = %d\n", mul(a, b));

    return 0;
}