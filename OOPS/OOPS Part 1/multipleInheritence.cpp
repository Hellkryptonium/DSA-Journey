#include <iostream>
#include <string>
using namespace std;

class Teacher {
public: 
    int salary;
    string subject;
};

class Student {
public:
    int rollno;
    float cgpa;
};

class TA : public Teacher, public Student {
public: 
    string name;
};

int main() {
    TA ta1;

    ta1.name = "shraddha khapra";
    ta1.subject = "C++";
    ta1.cgpa = 9.1;

    cout << ta1.name;

    return 0;
}