//8.5
#include<iostream>
#include<cstring>
using namespace std;

class String {
    char s[50];
public:
    void get_string() {
        cout << "Enter Name: ";
        cin >> s;
    }

    void disp_string() {
        cout << s;
    }

    // Overloading + operator to concatenate C-style strings
    String operator+(String a) {
        String n;
        strcpy(n.s, s);  // Copy the first string
        strcat(n.s, " "); // Add a space between the names
        strcat(n.s, a.s); // Concatenate the second string
        return n;
    }
};

int main() {
    String s1, s2, s3;

    cout << "First Name: ";
    s1.get_string();

    cout << "Last Name: ";
    s2.get_string();

    s3 = s1 + s2;

    cout << "Full Name: ";
    s3.disp_string();

    return 0;
}
