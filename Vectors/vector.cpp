#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec(4,1);
    cout << "size : " << vec.size() << endl;
    cout << "capacity : " << vec.capacity() << endl;

    vec.push_back(5);
    cout << "size : " << vec.size() << endl;
    cout << "capacity : " << vec.capacity() << endl;
    return 0;
}