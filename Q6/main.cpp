//6.3
#include <iostream>
#include <string>

using namespace std;

// Base class: Scheme
class Scheme {
protected:
    int scheme_id;
    string scheme_name;
    double outgoing_rate;
    double message_charge;

public:
    Scheme(int id, string name, double rate, double charge) :
        scheme_id(id), scheme_name(name), outgoing_rate(rate), message_charge(charge) {}

    void readSchemeDetails() {
        cout << "Enter Scheme ID: ";
        cin >> scheme_id;
        cout << "Enter Scheme Name: ";
        cin.ignore();  // Consume newline character from previous input
        getline(cin, scheme_name);
        cout << "Enter Outgoing Rate: ";
        cin >> outgoing_rate;
        cout << "Enter Message Charge: ";
        cin >> message_charge;
    }

    void displaySchemeDetails() const {
        cout << "Scheme ID: " << scheme_id << endl;
        cout << "Scheme Name: " << scheme_name << endl;
        cout << "Outgoing Rate: " << outgoing_rate << endl;
        cout << "Message Charge: " << message_charge << endl;
    }
};

// Derived class: Customer
class Customer : public Scheme {
private:
    int cust_id;
    string name;
    string mobile_no;
    double call_duration;
    int message_count;

public:
    Customer(int id, string n, string mob, int schemeId, string schemeName, double rate, double charge) :
        Scheme(schemeId, schemeName, rate, charge), cust_id(id), name(n), mobile_no(mob), call_duration(0.0), message_count(0) {}

    void readCustomerDetails() {
        cout << "Enter Customer ID: ";
        cin >> cust_id;
        cout << "Enter Customer Name: ";
        cin.ignore();  // Consume newline character from previous input
        getline(cin, name);
        cout << "Enter Mobile Number: ";
        cin >> mobile_no;
        cout << "Enter Call Duration (in minutes): ";
        cin >> call_duration;
        cout << "Enter Number of Messages: ";
        cin >> message_count;
    }

    void displayCustomerDetails() const {
        cout << "Customer ID: " << cust_id << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Mobile Number: " << mobile_no << endl;
        cout << "Call Duration: " << call_duration << " minutes" << endl;
        cout << "Number of Messages: " << message_count << endl;
    }

    // Calculate the bill amount
    double calculateBill() const {
        double call_cost = call_duration * outgoing_rate;
        double message_cost = message_count * message_charge;
        return call_cost + message_cost;
    }
};

int main() {
    Customer customer(1, "John Doe", "1234567890", 1, "Basic", 0.5, 0.2); // Example customer with scheme

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Read Customer Details\n";
        cout << "2. Display Customer Details\n";
        cout << "3. Display Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                customer.readCustomerDetails();
                break;
            case 2:
                customer.displayCustomerDetails();
                break;
            case 3:
                cout << "Bill Amount: " << customer.calculateBill() << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}