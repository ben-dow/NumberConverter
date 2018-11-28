#include <iostream>
#include "Converters.h"
#include <vector>
#include <string>

using namespace std;

int main(){


    // Makes code more readable for deciding which Conversion to execute
    enum NumberType{
        Binary = 1,
        Decimal = 2,
        Hex = 3
    };

    // Prompt the User for input data about which conversion is desired
    cout << "What Kind of Number is it?" << endl;
    cout << "(1) Binary" << endl;
    cout << "(2) Decimal" << endl;
    cout << "(3) Hex" << endl;

    int Type;
    cin >> Type;

    // Prompt the user for the Number to be used
    cout << "\nWhich number would you like to convert?" << endl;
    std::string ConversionNumber;
    cin >> ConversionNumber;

    NumberFactory * factory = new NumberFactory();

    Number *number =  factory->create(Type,ConversionNumber);
    

    cout << "What do you want to convert to?" << endl;
    cout << "(1) Binary" << endl;
    cout << "(2) Decimal" << endl;
    cout << "(3) Hex" << endl;

    int ConvertType;
    cin >> ConvertType;

    cout << "" << endl;


    string conversion;
    cout << "The converted number is: ";
    switch(ConvertType){
        case Binary: {
            cout << number->toBinary() << endl;
            break;
        }
        case Decimal: {
            cout << number->toDecimal() << endl;
            break;
        }
        case Hex: {
            cout << number->toHex() << endl;
            break;
        }
        default: {
            break;
        }
    } 




}