// Standard library functions
// Perform system level tasks
// File I/O, C-Strings, Error Handling (system error), Date/Time, Utilities (Math, Localization
// Process Control, System services).
// Check man page in terminal shows documentation.
#include <cstdio>
#include <cstring>
#include <cstdint>
#include <cerrno>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

constexpr int maxString = 1024;
constexpr int repeat = 5;

// Vector element printing
void printVectorContent(vector<int> &vec){
    // Uses range-based for-loop
    for (int &k : vec){
        printf("%d ", k);
    }
    printf("\n");
}

// Max length for binary files
constexpr size_t maxLenBFile = 111;
// Object to write to binary file.
struct fileInput{
    uint8_t paritionId; // 8 bits
    uint8_t dataLength; // 8 bits
    char msgData[maxLenBFile + 1]; // 112 bits
    // Total size of fileInput = 128 bits.
};

// File mode string - r, w, a, r+, w+...
int main(int argc, char **argv)
{
    /*
     *
     * Starting FIle I/O operations.
     */
    const char *fName = "runtest.txt";
    const char *inText = "Hello write this line!\n\n";

    // Create and write to file.
    puts("Writing to file.");
    FILE *fwriteIn = fopen(fName, "w");
    for (int k = 0; k < repeat; k++)
    {
        fputs(inText, fwriteIn);
    }
    fclose(fwriteIn);
    printf("Done wiritng.\n\n");

    // Read from the file.
    puts("Reading from File");
    // Output buffer.
    char outBuffer[maxString];
    FILE *freadOut = fopen(fName, "r");
    while (fgets(outBuffer, maxString, freadOut))
    {
        fputs(outBuffer, stdout); // stdout is the outfile for console
        // could be use for socket programming.
    }
    fclose(freadOut);
    remove(fName);
    printf("Done\n");
    // End of File I/O

    /*
     * Starting File I/O for Binary files.
     */
    const char *fNameB = "test.file";
    const char *cStrIn = "This is test c-string.";
    // Create and write
    puts("Writing Binary file.");
    // b flag indicate writing a binary file
    // This is important for platform like Windows not to
    // treat binary file as text file.
    FILE *binFile = fopen(fNameB, "wb");

    static fileInput msgInBuf;
    for (int k = 0; k < 5; k++)
    {
        msgInBuf.paritionId = k;
        msgInBuf.dataLength = (uint8_t) strlen(cStrIn);
        if (msgInBuf.dataLength > maxLenBFile)
        {
            msgInBuf.dataLength = maxLenBFile;
        }
        strncpy(msgInBuf.msgData, cStrIn, maxLenBFile);
        msgInBuf.msgData[msgInBuf.dataLength] = 0; // NULL terminate it
        fwrite(&msgInBuf, sizeof(fileInput), 1, binFile);
    }
    fclose(binFile);
    puts("Finished Writing binary file.");
    printf("Done. \n");

    // Read the binary file.
    puts("Reading binary file.");
    FILE *binReadFile = fopen(fNameB, "rb");
    // Storage for fetched data.
    fileInput outBuff;
    size_t rCounter;
    while ((rCounter = fread(&outBuff, sizeof(fileInput), 1, binReadFile) ))
    {
        printf("paritionId: %d, data lenght: %d, Data: %s\n", 
               outBuff.paritionId, outBuff.dataLength, outBuff.msgData);
    }
    fclose(binReadFile);
    remove(fNameB);
    // End of Binary File I/O

    /*
     * Starting File Management.
     */
    static const char *filename  = "testFile";
    FILE *fileHandler = fopen(filename, "w");
    fclose(fileHandler);
    puts("Finished Creating file.");

    // Rename the file.
    static const char *newFileName = "testFileNew";
    if (0 == rename(filename, newFileName))
    {
        puts("File Renamed");
    }

    // Remove file.
    if (remove(newFileName) == 0)
    {
        puts("File Deleted");
    }
    /*
     * End of Management.
     */

    /*
     * Uformatted character I/O
     */
    const int bufSize = 256;
    static char bufO[bufSize];
    fputs("prompt: ", stdout); // fputs doesnt add new line like puts does.
    fflush(stdout); // Get stuff written to the console or file.
    fgets(bufO, bufSize, stdin); // Gets character from console and write to buffer
    fputs(bufO, stdout); // Write buffer contents to console.

    /*
     * Formatted character I/O
     */
    int w = 5;
    long int lin = 18940393734;
    const char *cstr = "Test Printf";
    // printf is variadic function
    // fprintf is a version that takes output file argument
    printf("w: %d, lin: %ld, str: %s, length of str: %zd\n", w, lin, cstr, strlen(cstr));
    // We can replace stdout with a filename.
    fprintf(stdout, "w: %d, lin: %ld, str: %s, ength of str: %zd\n", w, lin, cstr, strlen(cstr));

    /*
     * String Functions
     */
    const static size_t maxBufSz = 128;
    const char *dataOne = "Data One";
    const char *dataTwo = "Data Two";
    char bufOne[maxBufSz];
    char bufTwo[maxBufSz];
    int k = 0;
    char c = 0;
    char *cpyPtr = nullptr;

    // strncpy - Copy a string.
    strncpy(bufOne, dataOne, maxBufSz);
    printf("bufOne contains: %s\n", bufOne);
    strncpy(bufTwo, dataTwo, maxBufSz);
    printf("bufTwo contains: %s\n", bufTwo);

    // strncat - String concatenation
    strncat(bufOne, "-partition1", maxBufSz - strlen(dataOne)-1);
    strncat(bufOne, dataTwo, maxBufSz-strlen(bufOne) - 1);
    printf("bufOne contains: %s\n", bufOne);

    // strnlen - Length of a string
    printf("Length of bufOne is %zd\n", strnlen(bufOne, maxBufSz));
    printf("Length of bufOne is %zd\n", strnlen(bufTwo, maxBufSz));

    // strcmp - Strings comparison
    k = strcmp(bufOne, bufTwo);
    printf("bufOne %s bufTwo (%d)\n", (k == 0) ? "==" : "!=", k);
    k = strcmp(bufTwo, dataTwo);
    printf("bufTwo %s dataTwo (%d)\n", (k == 0) ? "==" : "!=", k);

    // strchr - Find a char in string
    c = 'n';
    cpyPtr = strchr(bufOne, c);
    printf("Found?: %s\n", cpyPtr ? "Yes" : "No");
    if (cpyPtr)
    {
        printf("'%c' in bufOne is at position %ld\n", c, cpyPtr-bufOne);
    }

    // strstr - Find a string in string
    cpyPtr = strstr(bufOne, dataTwo);
    printf("Found?: %s\n", cpyPtr ? "Yes" : "No");
    if (cpyPtr)
    {
        printf("'%s' in bufOne is at position %ld\n", dataTwo, cpyPtr-bufOne);
    }

    /* End of string functions. */

    /*
     * Standard system error handling
     */
    printf("Current errno: %d\n", errno);
    printf("Erasing file that doesnt exist");
    remove("unknowfile.file");
    printf("errno becomes: %d\n", errno);
    // Report the error
    perror("ERROR: Cannot delete file");
    // Print error message directly.
    const char *errstr = strerror(errno);
    printf("ERROR: %s\n", errstr);

    // STL provides function like Vector, List, Set, map, iterator etc.
    // Vector: Random access container (Array)
    // List: Doubly Linked List - optimized for fast insert and delete.
    // Set: Ordered sequence container where elements are kept in strict order based on their values.
    // Map: associative containers where unique keys are used to access values.
    // stack: LIFO queue: FIFO deque: Double ended container (for pushing and poping data)
    
    /*
     * Vector
     */
    vector<int> vecInt = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Common Operation
    printf("Size: %zd\n", vecInt.size());
    printf("Front: %d\n", vecInt.front());
    printf("Back: %d\n", vecInt.back());
    // Iterating
    for (auto it = vecInt.begin(); it != vecInt.end(); ++it){
        printf("%d ", *it);
    }
    printf("\n");
    printf("6th element: %d\n", vecInt[5]);
    printf("4th element: %d\n", vecInt.at(3));
    printVectorContent(vecInt);

    // Insert
    vecInt.insert(vecInt.begin()+3, 100); // Insert at 4th position
    printf("New Size: %zd\n", vecInt.size());
    printVectorContent(vecInt);

    // push_back
    vecInt.push_back(500);
    printf("Size after push_back: %zd\n", vecInt.size());
    printVectorContent(vecInt);

    // Erase
    vecInt.erase(vecInt.begin()+3); // Erase at 4th position
    printf("Size after erasing: %zd\n", vecInt.size());
    printVectorContent(vecInt);

    /*
     * C-array
     */
    const static size_t arrSize = 10;
    int cArray[arrSize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Initialize a vector with c-array
    vector<int> vecIntFromCArray(cArray, cArray+arrSize);
    printVectorContent(vecIntFromCArray);

    // Vector of Strings
    vector<string> vecStr = {"one", "two", "three", "four", "five", "six", "seven"};
    for (string &vstr : vecStr){
        printf("%s ", vstr.c_str());
    }
    printf("\n");

    /*
     * string: STL container class operating on characters.
     */
    string exampleString = "Working with string container";
    string::iterator it;

    // Size & Length
    printf("Length of string: %lu\n", exampleString.length());
    printf("Size of a string: %lu\n", exampleString.size());

    // Concatenation
    string newStr = "is fun";
    printf("Concatenated Strings: ");
    cout << exampleString + newStr << endl;

    // String comparison
    cout << "Is exampleString == newStr" << ((exampleString == newStr) ? "yes" : "no") << endl;
    
    // Range-based iteration
    for (char c : exampleString)
    {
        printf("%c ", c);
    }
    printf("\n");

    // Insert/erase with iterator
    it = exampleString.begin() + 5;
    exampleString.insert(it, 'Q');
    printf("String is now: %s\n", exampleString.c_str());
    // Erase
    it = exampleString.begin()+3;
    exampleString.erase(it);
    printf("After erasing, string is now: %s\n", exampleString.c_str());

    // Replace
    exampleString.replace(5, 2, "Nooo");
    printf("After replacing, string is now: %s\n", exampleString.c_str());

    // Find
    size_t pos = exampleString.find("c");
    printf("First occurence of 'c' at pos: %zd\n", pos);
    pos = exampleString.rfind("n"); // Last occurence of 'n'
    printf("Last occurence of 'n' at pos: %zd\n", pos);

    //substr
    cout << "substring: " << exampleString.substr(5,5) << endl;

    return 0;
}