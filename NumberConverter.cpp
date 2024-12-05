#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string decimalToBinary(int decimal){
    string binary = "";
    while(decimal > 0){
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

string decimalToHexadecimal(int decimal){
    stringstream ss;
    ss << hex<< decimal;
    return ss.str();
}

int binaryToDecimal(string binary){
    int decimal = 0;
    int power = 0;
    for (int i = binary.length()-1; i>=0; i--){
        if(binary[i] == '1' ){
            decimal += pow(2,power);
        }
        power ++;
        }
        return decimal;
}

int hexadecimalToDecimal(string hexadecimal){
    int decimal =0;
    int power = 0;
    for(int i = hexadecimal.length()-1; i >=0; i--){
        int digit;
        
        if(hexadecimal[i] >= '0' && hexadecimal[i] <= '9'){
            digit = hexadecimal[i] - '0';
    }
        else{
            digit = hexadecimal[i] - 'A' + 10;
        }
        decimal = decimal + digit * pow(16,power);
        power++;
    }
    return decimal;
}

int main(){
    int choice;
    int decimalNumber; 
    string binaryNumber;
    string hexadecimalNumber;

    cout<<"Number converter"<< endl;
    cout<<"1. Decimal to Binary "<< endl;
    cout<<"2. Decimal to Hexadecimal "<< endl;
    cout<<"3. Binary to Decimal "<< endl;
    cout<<"4. Hexadecimal to Decimal "<< endl;
    cout<<"Enter your choice" << endl;
    cin>> choice;

    switch (choice){
    case 1:
        cout<<" Enter Decimal number"<< endl;
        cin>> decimalNumber;
        cout<< "Binary: "<< decimalToBinary(decimalNumber) <<endl;
        break;

    case 2:
        cout<<" Enter Decimal number"<< endl;
        cin>> decimalNumber;
        cout<< "Hexadecimal: "<< decimalToHexadecimal(decimalNumber) <<endl;
        break;

    case 3:
        cout<<" Enter Binary number"<< endl;
        cin>> binaryNumber;
        cout<< "Decimal: "<< binaryToDecimal(binaryNumber) <<endl;
        break;

    case 4:
        cout<<" Enter Hexadecimal number"<< endl;
        cin>> hexadecimalNumber;
        cout<< "Decimal: "<< hexadecimalToDecimal(hexadecimalNumber) <<endl;
        break;
    default:
        cout<<"Invalid choice, please enter correct choice! "<< endl;
        break;
    }
    return 0;
}