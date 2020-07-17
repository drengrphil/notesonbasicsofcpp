// Function Pointers Application
// This program demonstrate the use of function pointers
// Developed a simple onscreen menu option
/*
 *
 * Function pointer is a variable that stores the address of a function.
 * It could also be a pointer array that stores addresses of functions.
 */
#include <cstdio>
#include <stdlib.h>
using namespace std;

// function to test function pointer
void myIntFunc(int x){
    static int pointValue;
    pointValue += x;
    printf("New Points Value: %d\n", pointValue);
}

// Function pointer to myIntFunc
void (*fooFunc)(int);

const char * promptMenu();
int jumpOption(const char*);

void faFunc(){
    printf("faFunc is called.\n"); 
    fooFunc = myIntFunc; 
    fooFunc(1);
}

void fbFunc(){ 
    printf("fbFunc is called.\n"); 
    fooFunc = myIntFunc; 
    fooFunc(2);
}

void fcFunc(){
    printf("fcFunc is called.\n"); 
    fooFunc = myIntFunc; 
    fooFunc(3);
}

void fdFunc(){
    printf("fdFunc is called.\n"); 
    fooFunc = myIntFunc; 
    fooFunc(4);
}

void feFunc(){
    printf("feFunc is called.\n"); 
    fooFunc = myIntFunc; 
    fooFunc(5);
}

// Declare the function pointer as an array of functions
void (*funcsPointer[])() = {faFunc, fbFunc, fcFunc, fdFunc, fdFunc, feFunc};

// Comparator function passed as function pointer in qsort().
int customComparator(const void *firstArg, const void *secondArg);

// Alternatively, we could use Polymorphism and Virtual functions instead
// of function pointers.
class SorterObj
{
public:
    virtual int compare(const void *firstVal, const void *secondVal);            
};

class AscendSorted : public SorterObj
{
    virtual int compare (const void* firstArg, const void* secondArg)
    {
        int firstV = *(int*) firstArg;
        int secondV = *(int*) secondArg;
        if (firstV < secondV){
            return -1;
        } else if (firstV == secondV){
            return 0;
        } else {
            return 1;
        }
    }
};

int main(){
    while(jumpOption(promptMenu()));
    puts("\nDone.");

    // qsort() with function pointer as comparator
    int numArray[10];
    int k = 0;
    printf("unsorted num array:\n");
    for (k = 0; k < 10; ++k){
        numArray[k] = 10 - k;
        printf("%d ", numArray[k]);
    }
    printf("\n");
    qsort(numArray, 10, sizeof(int), customComparator);
    // Print sorted
    printf("sorted num array:\n");
    for (k = 0; k < 10; ++k){
        printf("%d ", numArray[k]);
    }
    printf("\n");

    // Using class and virtual function instead of function pointer
    // Virtual function still implements function pointer in the 
    // background.
    // AscendSorted sortOb;

    // cpp_qsort(numArray, 10, sizeof(int), sortOb.compare);

    return 0;
}

const char * promptMenu()
{
    puts("Choose an option:");
    puts("1. Function fa");
    puts("2. Function fb");
    puts("3. Function fc");
    puts("4. Function fd");
    puts("5. Function fe");
    printf(">> ");
    fflush(stdout); // Flush after prompt

    const int buffSize = 16;
    // Buffer for response
    static char userResponse[buffSize];
    // Get response from console
    fgets(userResponse, buffSize, stdin);
    return userResponse;
}

int jumpOption(const char* response)
{
    char code = response[0];
    if (code == 'q' || code == 'Q') return 0;
    // Length of the functions array
    int funLen = sizeof(funcsPointer)/sizeof(funcsPointer[0]);
    // Convert ASCII numeral to int
    int numI = (int) code - '0';
    if (numI < 1 || numI > funLen){
        puts("invalid choice");
        return 1;
    } else {
        funcsPointer[numI - 1]();
        return 1;
    }
}

/*
 * Other applications of function pointers
 * 1. Creating sort routine: whereby users can pass in a function to the sort function.
 * 2. Callback Functions: To setup "listener" or "callback" functions that are invoked
 *    when a particular event happens. E.g. when user click on a button and causes the
 *    interface to call a function to handle the event.
 *    Invokes the callback_func when button is clicked:
 *    void create_button(int x, int y, const char *text, function callback_func);
 *    void (*foo)(int);
 *    foo = &myIntFunc; OR foo = myIntFunc;
 *    foo(2); OR (*foo)(2)
 * Benefits of function pointers:
 *    1. Function pointers provide a way of passing around instructions for how to
 *       do something.
 *    2. Write flexible function s and librarier that allow programmer to choose
 *       behavior by passing function pointers as arguments.
 *    3. This flexibility can also be achieved by using classes with virtual functions.
 */

// Sorting routine using function pointers - write a generic sorting routine
//   similar to qsort() in C
// void qsort(void *base, size_t nmemb, size_t size,
//           int(*compar)(const void*, const void*));

// For the qsort function, we could write our own function pointer for the compar
int customComparator(const void *firstArg, const void *secondArg)
{
    int firstVal = *(int*)firstArg;
    int secondVal = *(int*)secondArg;

    if (firstVal < secondVal){
        return -1;
    } else if (firstVal == secondVal){
        return 0;
    } else {
        return 1;
    }
}