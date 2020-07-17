// Functions in Cpp
// Examples and howto
#include <cstdio>
#include <string>
#include <typeinfo>
#include <vector>
#include <new>

using namespace std;

// Function to Call by Value
// Only the local variable a
// is affected and the value passed
// to it remains unchanged.
void funcCallByVal(int a){
    ++a;
}

// Call by reference
void funcCallByRefVal(int &a){
    ++a;
}

// Function to Call by Reference
// It will change the actual variable
// passed to it.
void funcCallByRef(int *pVal){
    ++(*pVal);
}

// Function signature - different return type
// Volume of a cuboid.
long volumeCal(long a, long b, long c){
    return a * b * c;
}

// Volume of a sphere
double volumeCal(double r, int h){
    return 3.14159 * r * r * h;
}

// Function with forward declaration
void funcForwardDecl();
void funcStringPrinter(const string &S);

// Function with static - automatic storage on stack
// Every function invocation incremenets the same variable
void funcStaticVal(){
    static int vVal = 5;
    printf("vVal is incremented to: %d\n", ++vVal);
}

// Functions returning values
int funcReturnValue(int k){
    k *= 6;
    return k;
}

// Function returns value by reference
const string &funcReturnRef(){
    const static string s = "this is a func()";
    return s;
}

// Function pointer func
void funcPointerTest(){
    printf("This is a function pointer.\n");
}

int main()
{
    int i = 7;
    // Call by Value.
    funcCallByVal(i);
    printf("i is still same: %d\n", i);
    // Value will change when called by reference
    funcCallByRefVal(i);
    printf("i has changed: %d\n", i);

    // Call by Reference
    funcCallByRef(&i);
    printf("i is changed to: %d\n", i);

    printf("Volume of a cube: %ld\n", volumeCal(34, 4, 5));
    printf("Volume of a sphere: %.2f\n", volumeCal(34.5, 4));

    funcForwardDecl();
    string st = "this is a string";
    funcStringPrinter(st);

    // Calls to modify the same variable
    // static is used for persistent variable.
    funcStaticVal();
    funcStaticVal();
    funcStaticVal();

    // Function with return value.
    printf("Function returns: %d\n", funcReturnValue(10));

    // Function to return large object using reference rather 
    // than copying. Don't store huge object on stack.
    const string &s = funcReturnRef();
    printf("Function return referenced object: %s\n", s.c_str());

    // Function pointers: take the address of a function and 
    // assign it to a pointer.
    void (*ptrFunc)() = funcPointerTest;
    // Call the function pointer by dereferencing
    ptrFunc();

    return 0;
}

// Function definition
void funcForwardDecl(){
    printf("Print your name here:\n");
}

void funcStringPrinter(const string &S){
    printf("Value is: %s\n", S.c_str());
}