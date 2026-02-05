#include <stdio.h>

int factorial(int n){
    if (n<=1) return 1;
    return n * factorial(n - 1);
}

int fobonacci(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return fibonacci(n-1) + foibonacci(n-2);
}