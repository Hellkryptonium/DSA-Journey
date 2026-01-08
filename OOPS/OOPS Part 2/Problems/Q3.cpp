#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public: 
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person {
private:
    string studentId;
public:
    Student(string name, int age, string studentId) : Person(name, age) {
        this->studentId = studentId;
    }

    void displayStudentInfo() {
        cout << "name : " << this->name << endl;
        cout << "age : " << this->age << endl;
        cout << "studentId : " << this->studentId << endl;
    }
};

int main() {
    Student s1("harish", 20, "24scse");

    s1.displayStudentInfo();
    return 0;
}