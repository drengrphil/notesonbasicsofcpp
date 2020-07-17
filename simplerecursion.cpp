// Recursion
// Function calling itself.
// For every function call, memory is allocated for the local variables
// and other function call overheads still a factor.
// all these are placed on stack, which is a limited resource.
#include <cstdio>
using namespace std;

unsigned long int recursiveFactorial(unsigned long int n){
    if (n < 2) return 1;
    return recursiveFactorial(n-1)*n;
}

int main()
{
    unsigned long int n = 10;
    printf("Factorial of %ld is %ld\n", n, recursiveFactorial(n));
    return 0;
}