#include<iostream>
#include<string>
using namespace std;
string binary(int); // fun prototype or declaration of function

string binary(int decimal) {
    int remainder;
    string binaryStr;

    // decimal to binary
    while (decimal > 0) {
        remainder = decimal % 2;
        binaryStr = to_string(remainder) + binaryStr; // "1"+"" = "1"      // This will work as follow:
        decimal /= 2;                                 // "2"+"1" = "21"
    }                                                 // "3"+"21" = "321"

    // Ensure the binary representation is 8 bits
    while (binaryStr.length() < 8) {
        binaryStr = "0" + binaryStr;
    }

    return binaryStr;
}

int main() {
    int decimal;
    string text;
    cout << "Enter text: ";
    getline(cin,text);  // this use when we have spaces in string

    string binaryNumber;
    for (char ch : text) { //text string ka har character bari bari loop body main aye ga,Like "Subhan", loop six time chele ga, aur har dafa ek character sequence wise loop body main aye ga
        decimal = ch;      //har character ki decimal value "decimal" variable main store hojaye gi
        binaryNumber = binaryNumber + binary(decimal) + " ";
    }

    cout << "Your Text In Binary: " << binaryNumber << endl;
    return 0;
}