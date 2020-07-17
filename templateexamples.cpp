// Template: supporst generic program
// Generic programming is a code that works independent of type
// C++ is a strongly typed programming language, we can still write codes
// that are type agnostic - operating on objects without concern for the types
// of those objects.
// We can do a generic programming and leave the implementation details to the
// classes and operators.
// CAVEATS:
//    1.  Larger executables: compiler must generate specialization for every type contents
//    2.  Confusing error messages: compiler have hard time generating sensible error message
//        for templates, hence, debugging is challenging.
//    3.  Longer compile times: changes to header can lead to longer compile time.
// Use to implement template libraries
#include <cstdio>
#include<string>
using namespace std;

// You cannot define a template within a block.
// more powerful and less prone to error more than macros.
// Useful for manipulating containers.
template<typename T> // typename can be writen as <class T>, typename is less ambiguous
T maxof (T a, T b){
    return (a > b ? a : b);
}

int main (int argc, char **argv){
    int m = maxof<int>(7,9);
    printf("max is: %d\n", m);

    // This compares only the pointer and not actual string
    const char *mstr = maxof<const char*>("seven", "nine");
    printf("max is: %s\n", mstr);

    // Compare as string - compares alphabetically
    string mlitstr = maxof<string>("seven", "nine");
    printf("max is: %s\n", mlitstr.c_str());

    return 0;
}


