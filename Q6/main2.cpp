//6.2
#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
    int id;
    std::string name;
    double salaryScale;

public:
    Employee(int id, std::string name, double salaryScale) 
        : id(id), name(name), salaryScale(salaryScale) {}

    virtual double computePay(int hours) = 0;
};

class MaleEmployee : public Employee {
public:
    MaleEmployee(int id, std::string name, double salaryScale) 
        : Employee(id, name, salaryScale) {}

    double computePay(int hours) override {
        return hours * salaryScale;
    }
};

class FemaleEmployee : public Employee {
public:
    FemaleEmployee(int id, std::string name, double salaryScale) 
        : Employee(id, name, salaryScale) {}

    double computePay(int hours) override {
        return 40 * salaryScale;
    }
};

int main() {
    MaleEmployee maleEmployee(1, "John Doe", 20.0);
    FemaleEmployee femaleEmployee(2, "Jane Doe", 20.0);

    std::cout << "Male Employee Pay: " << maleEmployee.computePay(40) << std::endl;
    std::cout << "Female Employee Pay: " << femaleEmployee.computePay(40) << std::endl;

    return 0;
}