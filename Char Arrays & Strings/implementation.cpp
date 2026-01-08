#include <iostream>
using namespace std;



int main() {
    // char word[10];
    // cin >> word;
    
    char sentence[30];
    cin.getline(sentence,30,'*');

    cout << "Your word was : " << sentence << endl;

    return 0;
}