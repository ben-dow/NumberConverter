#include <vector>
#include <string>

// Makes code more readable for deciding which Conversion to execute
enum NumberType{
        Binary = 1,
        Decimal = 2,
        Hex = 3
    };

class Number {
    public:
        virtual std::string toBinary() = 0;
        virtual std::string toDecimal() = 0;
        virtual std::string toHex() = 0; 
    protected:
        std::string num;
};

class BinaryNumber: public Number {
    public:
         std::string toBinary();
         std::string toDecimal();
         std::string toHex(); 

        BinaryNumber(std::string usernum){
            num = usernum;
            
        }

};

class DecimalNumber: public Number {
    public:
         std::string toBinary();
         std::string toDecimal();
         std::string toHex(); 


        DecimalNumber(std::string usernum){
            num = usernum;
            
        }

};

class HexNumber: public Number {
    public:
         std::string toBinary();
         std::string toDecimal();
         std::string toHex(); 

        HexNumber (std::string usernum){
            num = usernum;
            
        }
};

class NumberFactory {
    public:
    Number* create(int type, std::string numstring);
};

//Helper Method
std::string ConvertVector(std::vector<int> vec);
