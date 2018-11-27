#include <iostream>
#include "Converters.h"
#include <vector>
#include <string>

using namespace std;

int main(){
    std::cout << __cplusplus;


    // Makes code more readable for deciding which Conversion to execute
    enum ConversionTypes{
        DecimalToBinary = 1,
        BinaryToDecimal = 2
    };

    // Prompt the User for input data about which conversion is desired
    cout << "Select the conversion you would like complete" << endl;
    cout << "(1) Decimal to Binary" << endl;
    cout << "(2) Binary to Decimal" << endl;
    int ConversionType;
    cin >> ConversionType;

    // Prompt the user for the Number to be used
    cout << "\nWhich number would you like to convert?" << endl;
    int ConversionNumber;
    cin >> ConversionNumber;


    switch(ConversionType){

        case DecimalToBinary: {
            cout << "\nConverting Decimal Number to Binary" << endl;
            string  binaryStorage = DecimalToBinaryConverter(ConversionNumber);
            cout << binaryStorage << endl;
            break;
        }

        case BinaryToDecimal: {
            cout << "Convering Binary Number to Decimal" << endl;
            string DecimalStorage = BinaryToDecimalConverter(ConversionNumber);
            cout << DecimalStorage << endl;
            break;
        }
        
        default: {
            cout << "Invalid Conversion Type" << endl;
            break;
        }
    
    
    } 

}