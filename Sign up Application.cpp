#include <iostream>
#include <string>
using namespace std;

// Class Definition

class MUser {
private:
    string name;
    string password;
    string role;

public:
    MUser() {
        cout << "Default Constructor is Called!" << endl;
    }

    MUser(string na, string pass, string r) {
        name = na;
        password = pass;
        role = r;
        cout << "Parameterized Constructor is Called!" << endl;
    }

    MUser(const MUser& user) {
        name = user.name;
        password = user.password;
        role = user.role;
        cout << "Copy Constructor Called!" << endl;
    }

    ~MUser() {
        cout << "Destructor Called for user: " << name << endl;
    }

    bool signIn(string n, string p) {
        if (n == name && p == password) return true;
        else return false;
    }

    void showRole() {
        cout << "Role: " << role << endl;
    }

    void showData() {
        cout << "Name: " << name << " | Role: " << role << endl;
    }
};


// Main Function

int main() {
    cout << "------------------------------------------\n";
    cout << "          SIGN-IN / SIGN-UP APP          \n";
    cout << "------------------------------------------\n\n";

    cout << "------ SIGN UP -------" << endl;
    string name, password, role;

    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Role (Admin/User): ";
    cin >> role;

    MUser* user1 = new MUser(name, password, role);
    cout << "\nUser created successfully!\n";

    cout << "\n--- SIGN IN ---" << endl;
    string n, p;
    cout << "Enter Name: ";
    cin >> n;
    cout << "Enter Password: ";
    cin >> p;

    if (user1->signIn(n, p)) {
        cout << "Login Successful!" << endl;
        user1->showData();
    }
    else {
        cout << "Invalid Credentials!" << endl;
    }

    // ---------- Copy Constructor Example ----------
    cout << "\nCreating a copy of user1..." << endl;
    MUser user2 = *user1; // invokes Copy Constructor
    user2.showRole();

    // Memory clean up
    delete user1;

    return 0;
}
