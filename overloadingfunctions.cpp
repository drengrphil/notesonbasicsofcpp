// Overloading functions
// Compiler decides which function to call based on the function signature.
// In C++, functions are distinguished by their signatures.
#include <cstdio>
#include <cstdarg> // Micros, definitions, and types for variadic functions.
using namespace std;

/*
 *
 * Overloaded functions:
 */
// Volume of a cylinder
double computeVolume(double r, double h){
    const static double pi = 3.141592653589793;
    printf("Cylinder of %.3lf x %.3lf\n", r, h);
    return pi * r * r * h;
}

// Volume of a cuboid
double computeVolume(double a, double b, double c){
    printf("Cylinder of %.3lf x %.3lf x %.3lf\n", a, b, c);
    return a * b * c;
}

// Volume of a cube
double computeVolume(double a){
    printf("Cube of %.3lf\n", a);
    return a * a * a;
}

/*
 *
 * Variadic functions: taking varying number of arguments
 * Useful in cases when we don't know the number of args ahead
 * of time.
 */
// First argument is int count of remaining arguments
// ... represents args that are doubles to compute average
double computeAverage(const int countArg, ...)
{
    va_list ap;
    int k;
    double total = 0.0;

    va_start(ap, countArg);
    for (k = 0; k < countArg; ++k){
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total/countArg;
}

// Another variadic function
int printMessage(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int rc = vfprintf(stdout, fmt, ap);
    puts("");
    va_end(ap);
    return rc;
}

int main(){
    printf("Volume of a cube: %.3lf\n", computeVolume(9.0));
    printf("Volume of a cylinder: %.3lf\n", computeVolume(9.0, 3.0, 3.0));
    printf("Volume of a cuboid: %.3lf\n", computeVolume(2.0, 3.0, 4.0));

    printMessage("Output:");
    printMessage("Average Computed: %lf", computeAverage(4, 6.0, 3.4, 10.5, 11.2));

    return 0;
}