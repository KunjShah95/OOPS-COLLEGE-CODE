// 6.1
#include<iostream>
#include<cstring>
using namespace std;
class String{
    private:
    char *str; // pointer to store the string
    public:
    //default constructor
    String()
    {
        str=new char[1];
        str[0] = '\0'; //empty string
    }
   // parameterized constructor
    String(const char * inputStr) {
        str = new char[strlen(inputStr) + 1]; // allocate memory for the string
        strcpy(str, inputStr); // copy the string
    }
    //copy constructor
    String(const String &obj) {
        str = new char[strlen(obj.str) + 1]; // allocate memory for the string
        strcpy(str, obj.str); // copy the string
    }

   void display() const{
    cout<<str<<endl;

   }
};
int main()
{
    String s1;
    cout<<"Default constructor"<<endl;
    s1.display();
    String s2("Hello, World!");
    cout<<"Parameterized constructor"<<endl;
    s2.display();
    String s3(s2);
    cout<<"Copy constructor"<<endl;
    s3.display();
    return 0;
}