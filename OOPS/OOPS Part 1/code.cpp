#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    float cgpa;

public:
    void getPercentage() {
        cout << (cgpa*10) << "% \n";
    }

    //Setters
    void setName(string nameVal) {
        name = nameVal;
    }

    void setCgpa(float cgpaVal) {
        cgpa = cgpaVal;
    }

    //Getters
    string getName() {
        return name;
    }

    int getCgpa() {
        return cgpa;
    }
};

int main() {
    Student s1;
    s1.setName("shradha");
    s1.setCgpa(9.1);

    cout << s1.getCgpa() << s1.getName();


     
    return 0;
}