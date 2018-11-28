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

    //Already in Decimal Format, Return as Is
    return num;
}

string DecimalNumber::toHex(){
    
    string HexResult = "";

    int intNum = stoi(num);

    int remainder;
    do {
        remainder = intNum % 16;

        if (remainder <= 9)
        {
            HexResult.append(to_string(remainder));
        }
        else{
            switch(remainder){
                case(10):{
                    HexResult.append("A");
                    break;
                }
                case(11):{
                    HexResult.append("B");
                    break;
                }
                case(12):{
                    HexResult.append("C");
                    break;
                }
                case(13):{
                    HexResult.append("D");
                    break;
                }
                case(14):{
                    HexResult.append("E");
                    break;
                }
                case(15):{
                    HexResult.append("F");
                    break;
                }
            }

        }

        intNum = intNum / 16;

        
    }while(intNum >= 1);

    //Converted Number is reversed for display value
    reverse(HexResult.begin(), HexResult.end()); 

    
    return HexResult;
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

    //First Convert to Decimal
    string DecimalConversion = this->toDecimal();

    //Use Existing Methods to Convert
    DecimalNumber decimalNumber = DecimalNumber(DecimalConversion);
    return decimalNumber.toHex();
}

/* HEX IMPLEMENTATIONS */
string HexNumber::toBinary(){
    return "Conversion Not Yet Implemented";
}

string HexNumber::toDecimal(){
    int DecimalResult = 0;

    int power = 0;
    for(int i = num.length() - 1; i >= 0; --i){
        if(isdigit(num[i])){
            int h = (int)num[i] - 48;
            DecimalResult += h * pow(16,power);
        }
        power++;
    }

    return to_string(DecimalResult);

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
