#include "Converters.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iterator>
#include <cmath>

using namespace std;

string DecimalToBinaryConverter(int num){
    
    vector<int> binaryStorage;

    int remainder;

    do {
        remainder = num % 2;
        
        binaryStorage.push_back(remainder);

        num = num / 2;

    } while(num >= 1);

    reverse(binaryStorage.begin(), binaryStorage.end());

    return ConvertVector(binaryStorage);
}

string BinaryToDecimalConverter(int num){
    
    string strnum = to_string(num);

    int power = 0;
    int decimalResult = 0;
    for(int i = strnum.length() -1; i >= 0; --i){
        std::string::size_type sz;

        int h = (int)strnum[i] - 48;
        decimalResult += h * pow(2, power);

        power++;     
    }
    

    return to_string(decimalResult);
}


string ConvertVector(vector<int> vec){
    std::ostringstream vts;

    if (!vec.empty()){
        copy(vec.begin(), vec.end(), ostream_iterator<int>(vts,""));
    }
    return vts.str();
}

void VectorPrinter(vector<int> conversion){

    for(int i = 0; i < conversion.size(); ++i){
        cout << conversion[i];
    }

    cout << endl;

}

