#include<iostream>
#include<cmath>
#include<string>
#include<limits>
using namespace std;

void for_text();   // fun prototype or declaration of function
void for_binary(); // fun prototype or declaration of function
string binary_to_text(string); // fun prototype or declaration of function
string text_to_binary(int);   // fun prototype or declaration of function

string binary_to_text(string binary){

    string text="";
    int integer;
    string byte;

    for(int i=0;i<binary.length();i=i+8){
        byte = binary.substr(i,8); //(i,8) means,i is starting index and 8 means upto 8 characters from index 0 to 7 

        int decimal=0, p=7;
        for (char ch : byte){ //byte string ka har character(0 or 1) bari bari loop body main aye ga,Like "00001111", loop 8 time run
            integer = ch - '0';  // '0'=48, '1'=49 --> if ch is '0' so 48-48 =0 in integer, same for if ch ='1'then 49-48 = 1 in integer
            decimal=decimal + integer*(pow(2,p)); // convert binary to decimal
            p=p-1;
        }
        char single_ch = decimal; // comvert decimal to character based on Ascii table
        text = text + single_ch;
    }
    return text;
}

string text_to_binary(int decimal) {

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

void for_text(){
    string binary;
    cout << "\nLimitations! Please don't Enter Spaces and any digits or char except 0 or 1:!"<<endl;
    cout << "Enter in Binary(0 or 1): ";
    getline(cin,binary);  // this use when we have spaces in string

    cout<<"Binary in Text: " <<binary_to_text(binary) <<endl<<endl;
}

void for_binary() {
    int decimal;
    string text;
    cout << "Enter text: ";
    getline(cin,text);  // this use when we have spaces in string

    string binaryNumber;
    for (char ch : text) { //text string ka har character bari bari loop body main aye ga,Like "Subhan", loop six time chele ga, aur har dafa ek character sequence wise loop body main aye ga
        decimal = ch;      //har character ki decimal value "decimal" variable main store hojaye gi
        binaryNumber = binaryNumber + text_to_binary(decimal) + " ";
    }

    cout << "Your Text In Binary: " << binaryNumber << endl<<endl;
}

int main(){
    int select;
    cout <<"\nWelcome! in Binary to Text and Text to Binary Translator"<<endl;
    cout <<"For Text to Binary Select 1"<<endl;
    cout <<"For Binary to Text Select 2"<<endl;
    cout <<"Select ";
    cin >>select;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear buffer for getline(),we need to #include<limits>

    for(int i=0; select != 1 && select != 2 ;i++){
        cout <<"Invalid! select from 1 or 2"<<endl;
        cout <<"Select ";
        cin >>select;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    }

    if (select == 1){
        for_binary();
    }
    if (select == 2){
        for_text();
    }
    return 0;
}

/*When you type something and press Enter, all the characters you typed, including the newline character (\n)
are stored in the input buffer.
Functions like cin >> and getline() retrieve data from this buffer.
e.g when you type 42 and press enter, then cin will take 42 and leave \n in the input buffer which cause unexpected
result, same as here, select take 1\n or 2\n , \n will left and use as input for others, getline() read it as 
empty input and programs end.

To fix this, you need to clear the input buffer after using cin by calling cin.ignore() Without this line,
if you use getline() after cin >> select, getline() will immediately read the leftover \n
and think that the user has entered an empty string
*/