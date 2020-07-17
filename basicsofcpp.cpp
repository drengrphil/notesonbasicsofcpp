// Covers all the basics of CPP.

#include <cstdio>
#include <string>
#include <typeinfo>
#include <vector>
#include <new>
#include <iostream>
#include <sstream>

using namespace std;

// Memory size
constexpr size_t memSize = 1024;

// Print Contents of an int array.
void printIntArrayContents(int arr[], int arrLen){
    int k = 0;
    while (k < arrLen){
        printf("%d, ", arr[k]);
	k++;
    }
    printf("\n");
}

// Print char of a string
void printCharArrayContents(char str[]){
    for (char *cp = str; *cp; ++cp){
        printf("%c ", *cp);
    }
    printf("\n");
}

int &fcnWithRefArg(int &val){
        return ++val;
}

typedef unsigned char points_t;
typedef unsigned char rank_t;

struct score{
    points_t p;
    rank_t r;
};

// a byte is 8 bits
constexpr size_t byte = 8;

// String returning function
string returnString(){
    return string("This is a string.");
}

// Class to demonstrate static qualifier.
class Sclass{
public:
    int static_value(){
        // static makes variable for program lifetime.
        // becomes shared variable for every instance of class.
        static int xval = 7;
        return ++xval;
    }
};

// Function to demonstrate static qualifier
int qualifierFunc(){
    static int x = 7;
    return x++;
}

// struct with bitfields
// Bitfields are used to reduce memory consumption
// When a program requires a number of integer variables
// which always have low values.
struct preferences{
    bool likeMusic : 1; // Use 1bit for the bool
    bool hasHair : 1;
    bool hasInternet : 1;
    bool hasDinosaur : 1;
    unsigned int numberOfChildren : 4; // Use 4 bits.
};

// Union
union ipv4{
    uint32_t i32;
    struct {
        uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t d;
    } octets;
};

// Convert unsigned 8-bit to string
// Integer to binary return as string.
const char *u8_to_cstr(const uint8_t &x){
    static char buf[sizeof(x) * 8 + 1];
    for (char &c : buf) c = 0; // Reset buffer
    char *bp = buf;
    for (uint8_t bitmask = 0b10000000; bitmask; bitmask >>= 1){
        *(bp++) = x & bitmask ? '1' : '0';
    }
    return buf;
}

int main()
{
    // Set and initialize int array.
    int iArray[] = {1, 2, 3, 4, 5};

    // Iterate through the array.
    for (auto i : iArray)
    {
        printf("i is %d\n", i);
    }

    // Regular for loop
    int arrLen = (sizeof(iArray)/sizeof(int));
    for (int k = 0; k < arrLen; k++){
        printf("kth element is %d\n", iArray[k]);
    }

    // Using while loop
    int k = 0;
    while (k < arrLen){
        printf("kth element is %d\n", iArray[k]);
	++k;
    }

    // Working with Switch
    const int ONE = 1;
    const int TWO = 2;
    const int THREE = 3;
    const int FOUR = 4;

    int x = 3;

    switch(x){
        case ONE:
	    printf("one");
	    break;
	case TWO:
	    printf("two");
	    break;
	case THREE:
	    printf("three");
	    break;
	case FOUR:
	    printf("default");
	    break;
	default:
	    printf("default");
	    break;
    }


    int xVal = 7;
    int yVal = 42;
    
    // Pointer to xVal
    int *val = &xVal;

    printf("Value of xVal is %d\n", xVal);
    printf("Address of xVal is: %p\n", val);
    printf("Value stored is: %d\n", *val);

    // Reference
    int &y = xVal;
    printf("Reference Value: %d\n", y);

    // Primitive array - using pointer on array
    int intArrayValues[5] = {1, 2, 3, 4, 5};
    arrLen = sizeof(intArrayValues)/sizeof(int);

    int *inPtr = intArrayValues;
    *inPtr = 2; // Changes first element only.
    printIntArrayContents(intArrayValues, arrLen);

    // Change all elements using pointers
    int *end = intArrayValues + 5;
    while (inPtr != end){
        *inPtr *= 2;
	++inPtr;
    }
    // Print new contents of the array.
    printIntArrayContents(intArrayValues, arrLen);
    
    // Using for loop
    for (int *pt = intArrayValues; pt != end; ++pt){
        *pt *= 2; // Multiply each element by 2.
    }
    printIntArrayContents(intArrayValues, arrLen);

    // Primitive String
    char str[] = "String";
    // OR
    char str2[] = {'S', 't', 'r', 'i', 'n', 'g', 0};
    printCharArrayContents(str);

    // Using range based iterator
    for (char c : str2){
       if (c == 0) break;
       printf("%c ", c);
    }
    printf("\n");

    /*
     * Data Types
     */
    // Integer
    int xLiteral = 147; // Literal integer value.
    printf("Int value is %d\n", xLiteral);
    // Oct representation
    int xOct = 0223; // Leading zero makes it in base 8 (octet)
    printf("Value still %d\n", xOct);
    // Hexdecimal (base 16)
    int xHex = 0x0093;
    printf("Value still %d\n", xHex);
    // Binary Format
    int xBin = 0b010010011;
    printf("Value is still %d\n", xBin);

    // Standard Ints sizes
    printf("sizeof int8_t is %ld bits\n", sizeof(int8_t)*byte);
    printf("sizeof int16_t is %ld bits\n", sizeof(int16_t)*byte);
    printf("sizeof int32_t is %ld bits\n", sizeof(int32_t)*byte);
    printf("sizeof int64_t is %ld bits\n", sizeof(int64_t)*byte);

    // Float type
    float f; double df; long double ldf;
    f = 500.0;
    printf("Value of a float: %f\n", f);
    printf("Size of float: %ld\n", sizeof(f)*byte);
    printf("Size of double: %ld\n", sizeof(df)*byte);
    printf("Size of long double: %ld\n", sizeof(ldf)*byte);

    // C-string
    char cstringVal[] = "Strings";
    printf("C-string type: %s\n", cstringVal);
    for (unsigned int k = 0; cstringVal[k]; k++){
        printf("%02d: %c\n", k, cstringVal[k]);
    }

    // Char pointer
    char const *charPtr = "CharPointer";
    // Change what's pointing to
    // *charPtr = "foo";
    for (unsigned int k = 0; charPtr[k]; ++k){
        printf("%2d: %c\n", k, charPtr[k]);
    }
    // Literal strings concatenation.
    // charPtr += "foo";
    printf("%s\n", charPtr);
    const char *strCon = "string for" "foo";
    printf("%s\n", strCon);

    // Append to end of string
    // using push_back(), +=, append(), insert, and stringstream
    string sTest = "Test append";
    char charToAdd = '+';
    sTest.push_back(charToAdd);
    printf("push_back op: %s\n", sTest.c_str());
    sTest += charToAdd;
    printf("+= op: %s\n", sTest.c_str());
    sTest.append(1, charToAdd);
    printf("using append(): %s\n", sTest.c_str());
    sTest.insert(sTest.length(), 1, charToAdd);
    printf("using insert(): %s\n", sTest.c_str());
    stringstream stream;
    stream << sTest << charToAdd;
    stream << sTest << "Added part";
    stream >> sTest;
    printf("using stringstream(): %s\n", sTest.c_str());

    // Vector
    vector<int> vecVar = {1,2,3,4,5};
    // Use of auto
    for (auto it = vecVar.begin(); it != vecVar.end(); ++it){
        printf("Values: ");
	    printf("%d ", *it);
    }
    printf("\n");

    // Auto type
    auto xStr = returnString(); // Compiler knows x is a string.
    printf("x is: %s\n", xStr.c_str());
    // Check variable type using typeid
    if (typeid(x)== typeid(string)) printf("x is string\n");

    // struct
    score s = {5, 1};
    printf("Score: %d points and %d rank\n", s.p, s.r);

    // qualifier - static
    // static variable in a function is same for
    // all function calls.
    printf("Demonstrate static qualifier\n");
    int kVal = 42;
    kVal = qualifierFunc();
    printf("Int val is: %d\n", kVal);
    kVal = qualifierFunc();
    printf("Int val is: %d\n", kVal);
    kVal = qualifierFunc();
    printf("Int val is: %d\n", kVal);

    // Qualifier defined in a class
    // static variable is the same location for all
    // class instances.
    Sclass a; Sclass b; Sclass c;
    printf("Int val in class a: %d\n", a.static_value());
    printf("Int val in class b: %d\n", b.static_value());
    printf("Int val in class c: %d\n", c.static_value());

    // Function with reference object to avoid
    // copying object of known size.
    // Pass reference to the object to a function.
    int valToPass = 5;
    int &valRef = valToPass;
    printf("Before changing: %d\n", valRef);
    valRef = 100;
    printf("After changing: %d\n", valRef);

    // Pass the reference to the function
    int result = fcnWithRefArg(valToPass);
    printf("Result: %d\n", result);


    // Working with struct with bitfields
    preferences homeOwner;
    homeOwner.likeMusic = true;
    homeOwner.hasHair = false;
    homeOwner.hasInternet = true;
    homeOwner.hasDinosaur = false;
    homeOwner.numberOfChildren = 3;
    // Size of the struct after using bitfields.
    printf("sizeof homer: %ld bits\n", sizeof(homeOwner)*8);

    // Union
    // provides different representation of the same data
    // Purpose is to save memory by using the same memory
    // region for storing different objects at different times.
    // Union holds at most one "active" member at each moment
    // of a program time.
    ipv4 addr;
    addr.octets = {192, 168, 73, 42};
    printf("addr is %d.%d.%d.%d is %08x\n", addr.octets.a, addr.octets.b, 
           addr.octets.c, addr.octets.d, addr.i32);
    
    // Bitwise operators
    // Allows binary operation on integer values
    uint8_t xbw = 5;
    uint8_t ybw = 10;
    uint8_t z = xbw | ybw; // Bitwise OR (Performs OR operation bitwise)
    uint8_t andOp = xbw & ybw; // Bitwise AND
    uint8_t xorOP = xbw^ybw; // Bitwise XOR
    uint8_t norOP = ~ybw; // Bitwise NOT
    uint8_t shiftOP = ybw >> 1; // Bitwise shift by 1bit

    printf("x is %s\n", u8_to_cstr(xbw));
    printf("y is %s\n", u8_to_cstr(ybw));
    printf("OR operation: %s\n", u8_to_cstr(z));
    printf("AND operation: %s\n", u8_to_cstr(andOp));
    printf("XOR operation: %s\n", u8_to_cstr(xorOP));
    printf("NOT operation %s\n", u8_to_cstr(norOP));
    printf("Shift Operation: %s\n", u8_to_cstr(shiftOP));

    // Working with "new" operator
    long int *inprt;
    // Allocate mem
    inprt = new(nothrow) long int[memSize]; // No try and catch
    // Mannually catch the error
    if (inprt == nullptr){
        fprintf(stderr, "Cannot allocate memory\n");
        return 1;
    }

    // Or use try and catch
    try{
        inprt = new long int[memSize];
    } catch  (std::bad_alloc & ba){
        fprintf(stderr, "Cannot allocate memory (%s)\n", ba.what());
    }

    // Fill up the array
    for (long int k = 0; k < memSize; ++k){
        inprt[k] = k;
    }

    // Print array.
    for (long int k = 0; k < memSize; ++k){
        printf("%ld ", inprt[k]);
    }
    printf("");

    // Deallocate mem
    delete [] inprt; // Remove [] for non-array pointer - delete objName.

    return 0;
}
