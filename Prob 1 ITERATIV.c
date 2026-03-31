#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n)
{
    int f0 = 0, f1 = 1, fib, loop;
    printf("%d %d", f0, f1);
    for(loop = 1; loop <= n - 2; loop++)
    {
        fib = f0 + f1;
        f0 = f1;
        f1 = fib;
        printf(" %d", fib);
    }
}

int main()
{
    fibonacci(30);
}