// iosstream file/formatting
/* iostream for interfacing with the console, reading from and writing to a file. */
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    // cout and cin
    string strVal;
    cout << "Enter a name: ";
    cin >> strVal;
    cout << "Your Name is " << strVal << endl;

    // Integer formatting
    printf("Integer Formatting: \n");
    int val1 = 50, val2 = 500, val3 = 6060;
    // Default int value
    cout << "Default: " << val1 << "," << val2 << "," << val3 << endl;
    cout << "Hex: " << hex << val1 << "," << val2 << "," << val3 << endl; // Hex
    cout << "Hex with base: " << showbase << hex << val1 << "," << val2 << "," << val3 << endl;
    cout << "Octal with base: " << oct << val1 << "," << val2 << "," << val3 << endl;
    cout << "Default: " << noshowbase << dec << val1 << "," << val2 << "," << val3 << endl;
    
    // Floating point formatting options
    printf("Floating Point formatting:");
    double valD1 = 3.1415926534, valD2 = 1234.5, valD3 = 4.2e-10;
    cout << "Default: " << valD1 << " " << valD2 << " " << valD3 << endl;
    cout << "Fixed: " << fixed << valD1 << " " << valD2 << " " << valD3 << endl;
    cout << "Scientific: " << scientific << valD1 << " " << valD2 << " " << valD3 << endl;
    // Set precision
    cout << "Fixed (3): " << setprecision(3) << valD1 << " " << valD2 << " " << valD3 << endl;
    cout << "Scientific: " << setprecision(7) << valD1 << " " << valD2 << " " << valD3 << endl;
    cout.unsetf(ios_base::floatfield);
    cout << "Default: " << valD1 << " " << valD2 << " " << valD3 << endl;

    /* String formatting */
    printf("String formatting");
    string strVal1 = "Two dogs walk";
    string strVal2 = "down the street";
    string strVal3 = "in the middle of the night.";

    cout << strVal1 << strVal2 << strVal3 << endl;
    cout << setw(64) << right << strVal1 << endl;
    cout << setw(64) << right << strVal2 << endl;
    cout << setw(64) << right << strVal3 << endl;

    cout << setfill('-') << setw(64) << right << strVal1 << endl;
    cout << setfill('-') << setw(64) << right << strVal2 << endl;
    cout << setfill('-') << setw(64) << right << strVal3 << endl;
    cout << left << strVal1 << endl;


    /*
     * File writing with I/O stream.
     */
    static int lineNum = 0;
    static int partitionId = 0;
    static const char *partitionData = "Rough data to store";
    static const char *dataMapOnDisk = "blockRangeMap.txt";

    // Create and write to file
    printf("Writing to file.\n");
    ofstream ofile(dataMapOnDisk);
    ofile << ++lineNum << " " << ++partitionId << " " << partitionData << endl;
    ofile << ++lineNum << " " << ++partitionId << " " << partitionData << endl;
    ofile << ++lineNum << " " << ++partitionId << " " << partitionData << endl;
    ofile.close();

    // Read the file
    printf("Reading from file.\n");
    static char outBuffer[128];
    ifstream infile(dataMapOnDisk);
    while (infile.good()){
        infile.getline(outBuffer, sizeof(outBuffer));
            cout << outBuffer << endl;
    }
    infile.close();

    remove(dataMapOnDisk);


    return 0;
}