// Find a positive integer not present in a given array.
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

int smallestPositiveValue(vector<int> &Arr){
    int positiveVal = 0;
    if (Arr.empty()){
        return positiveVal;
    }

    // Store values seen so far.
    bool presentValues[Arr.size()];
    for (int k = 0; k < Arr.size(); k++){
        if (Arr[k] > 0 && Arr[k] <= Arr.size()){
	    presentValues[Arr[k]] = true;
	}
    }

    for (int k = 0; k < Arr.size(); k++){
        if (!presentValues[k]){
	    return k;
	}
    }

    positiveVal = Arr.size() + 1;
    return positiveVal;
}

int main(){
    vector<int> arr = {23, 1, 8, 19};
    vector<int> arr2 = {-1, 3, 5};
    int result = smallestPositiveValue(arr);
    cout << result << endl;
    result = smallestPositiveValue(arr2);
    cout << result << endl;
}
