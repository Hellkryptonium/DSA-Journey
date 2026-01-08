#include <iostream>
#include <string>
using namespace std;

class User {
private: 
    string id;
    string password;

public:
    string username;

    User() {}

    User(string id) {
        this->id = id;
    }

    // Setter
    string setPassword(string passval) {
        return password = passval;
    }

    // Getter
    string getPassword() {
        return password;
    }
};

int main() {
    User u1 = User("123a");
    u1.username = "harish";
    u1.setPassword("1234");

    cout << u1.username << " " << u1.getPassword();
 
    return 0;
}