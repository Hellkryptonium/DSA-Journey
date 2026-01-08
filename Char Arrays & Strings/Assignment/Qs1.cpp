#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int lowerCaseVowelCount(string str) {
    int vowCount=0;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ) {
            vowCount++;
        }
    }
    return vowCount;
}

int main() {
    string str;
    cout << "Please enter your string: ";
    getline(cin,str);
    cout << str;
    cout << lowerCaseVowelCount(str);
    return 0;
}