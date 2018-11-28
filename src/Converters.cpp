#include "Converters.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iterator>
#include <cmath>

using namespace std;

/* DECIMAL IMPLEMENTATIONS */
string DecimalNumber::toBinary(){
    
    vector<int> binaryStorage;

    int intNum = stoi(num);

    int remainder;

    do {
        remainder = intNum % 2;
        
        binaryStorage.push_back(remainder);

        intNum = intNum / 2;

    } while(intNum >= 1);

    reverse(binaryStorage.begin(), binaryStorage.end());

    return ConvertVector(binaryStorage);
}

string DecimalNumber::toDecimal(){
    return num;
}

string DecimalNumber::toHex(){
    return "Conversion Not Yet Implemented";
}

/* BINARY IMPLEMENTATIONS */
string BinaryNumber::toBinary(){
    return num;
}


string BinaryNumber::toDecimal(){

    int power = 0;
    int decimalResult = 0;
    for(int i = num.length() -1; i >= 0; --i){
        std::string::size_type sz;

        int h = (int)num[i] - 48;
        decimalResult += h * pow(2, power);

        power++;     
    }

    return to_string(decimalResult);
}

string BinaryNumber::toHex(){
    return "Conversion Not Yet Implemented";
}

/* HEX IMPLEMENTATIONS */
string HexNumber::toBinary(){
    return "Conversion Not Yet Implemented";
}

string HexNumber::toDecimal(){
    return "Conversion Not Yet Implemented";

}

string HexNumber::toHex(){
    return num;
}

Number* NumberFactory::create(int type, std::string numstring){

    switch(type){

        case Binary: {
            cout << "Creating Binary Number" << endl;
            return new BinaryNumber(numstring);
            break;
        }

        case Decimal: {
            return new DecimalNumber(numstring);
            break;
        }
        case Hex: {
            return new HexNumber(numstring);
            break;

        }
        default: {
            cout << "Invalid Number Type" << endl;
            exit('E');
            break;
        }

    }
}



string ConvertVector(vector<int> vec){
    std::ostringstream vts;

    if (!vec.empty()){
        copy(vec.begin(), vec.end(), ostream_iterator<int>(vts,""));
    }
    return vts.str();
}
