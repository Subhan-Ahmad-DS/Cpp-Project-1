#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string binary_to_text(string); // fun prototype or declaration of function

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

int main(){
    string binary;
    cout << "\nLimitations! Please don't Enter Spaces and any digits or char except 0 or 1:!"<<endl;
    cout << "Enter in Binary(0 or 1): ";
    getline(cin,binary);  // this use when we have spaces in string

    cout<<"Binary in Text: " <<binary_to_text(binary) <<endl<<endl;
    return 0;
}