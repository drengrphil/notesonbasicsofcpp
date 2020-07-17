// Basic practice problems in C++
// From tutorial on codility.

// Binary gap: maximum sequence of consecutive zeros that is surrounded by ones
// at both ends in the binary representation of N.
// For example: [1, 0, 0, 1, 0] has maximum 2 consecutive zeros.
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
int findSequenceOfZeros(vector<int>& numArr){
    if (numArr.size() == 0){
        return 0;
    }

    // Store  count of zeros
    int countZeros = 0;
    // Keep maximum count.
    int maxNumOfZeros = 0;

    for (int k = 0; k < numArr.size(); k++){
        if (numArr[k] == 0){
	    countZeros += 1;
	} else if (numArr[k] == 1){
	    maxNumOfZeros = max(maxNumOfZeros, countZeros);
            countZeros = 0;	    
	}
    }

    if (countZeros > maxNumOfZeros)
	    maxNumOfZeros = countZeros;

    return maxNumOfZeros;
}


int main(){
    vector<int> biNumbers;
    int N = 1041;
    biNumbers.reserve(32);
    for (int k = 0; N > 0; k++){
        biNumbers.push_back(N%2);
	N = N/2;
    }

    /*for (unsigned int i = 0; i < biNumbers.size(); i++){
        cout << "Binary: " << biNumbers[i] << endl;
    }*/
    for (auto i = biNumbers.begin(); i != biNumbers.end(); i++){
        cout << *i << ' ';
    } 
    int result = findSequenceOfZeros(biNumbers);
    cout << result << endl;
}
