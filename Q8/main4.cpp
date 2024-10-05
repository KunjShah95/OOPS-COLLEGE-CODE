// 8.6
#include <iostream>
using namespace std;
class Distance {
private:
    int feet;
    int inches;

public:
    // Constructor
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {
        // Normalize the distance
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    // Overload the == operator
    bool operator==(const Distance& d) const {
        return (feet == d.feet) && (inches == d.inches);
    }

    // Overload the < operator
    bool operator<(const Distance& d) const {
        if (feet < d.feet) {
            return true;
        } else if (feet == d.feet) {
            return inches < d.inches;
        }
        return false;
    }

    // Overload the > operator
    bool operator>(const Distance& d) const {
        return !(*this < d) && !(*this == d);
    }

    // Function to display the distance
    void display() const {
        std::cout << feet << " feet " << inches << " inches" << std::endl;
    }
};

int main() {
    Distance d1(5, 10); // 5 feet 10 inches
    Distance d2(6, 2);  // 6 feet 2 inches
    Distance d3(5, 10); // 5 feet 10 inches

    std::cout << "Distance 1: ";
    d1.display();
    std::cout << "Distance 2: ";
    d2.display();
    std::cout << "Distance 3: ";
    d3.display();

    // Test equality
    if (d1 == d3) {
        std::cout << "Distance 1 is equal to Distance 3." << std::endl;
    } else {
        std::cout << "Distance 1 is not equal to Distance 3." << std::endl;
    }

    // Test less than
    if (d1 < d2) {
        std::cout << "Distance 1 is less than Distance 2." << std::endl;
    } else {
        std::cout << "Distance 1 is not less than Distance 2." << std::endl;
    }

    // Test greater than
    if (d2 > d1) {
        std::cout << "Distance 2 is greater than Distance 1." << std::endl;
    } else {
        std::cout << "Distance 2 is not greater than Distance 1." << std::endl;
    }

    return 0;
}