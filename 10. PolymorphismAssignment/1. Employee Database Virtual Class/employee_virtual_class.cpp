#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Virtual base class to avoid diamond problem
class Person {
protected:
    string name;
    int age;
    string address;
    
public:
    Person() : name(""), age(0), address("") {}
    
    Person(string n, int a, string addr) : name(n), age(a), address(addr) {}
    
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
    
    virtual ~Person() {}
};

// Virtual inheritance from Person
class Employee : virtual public Person {
protected:
    int employeeId;
    double salary;
    
public:
    Employee() : employeeId(0), salary(0.0) {}
    
    Employee(string n, int a, string addr, int id, double sal) 
        : Person(n, a, addr), employeeId(id), salary(sal) {}
    
    void display() override {
        cout << "Employee ID: " << employeeId << endl;
        Person::display();
        cout << "Salary: $" << salary << endl;
    }
};

// Virtual inheritance from Person
class Manager : virtual public Person {
protected:
    string department;
    int teamSize;
    
public:
    Manager() : department(""), teamSize(0) {}
    
    Manager(string n, int a, string addr, string dept, int team) 
        : Person(n, a, addr), department(dept), teamSize(team) {}
    
    void display() override {
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Team Size: " << teamSize << endl;
    }
};

// Multiple inheritance using virtual base class
class ManagerEmployee : public Employee, public Manager {
private:
    string projectName;
    
public:
    ManagerEmployee() : projectName("") {}
    
    ManagerEmployee(string n, int a, string addr, int id, double sal, 
                    string dept, int team, string proj) 
        : Person(n, a, addr), Employee(n, a, addr, id, sal), 
          Manager(n, a, addr, dept, team), projectName(proj) {}
    
    void inputDetails() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Employee ID: ";
        cin >> employeeId;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Department: ";
        cin.ignore();
        getline(cin, department);
        cout << "Enter Team Size: ";
        cin >> teamSize;
        cout << "Enter Project Name: ";
        cin.ignore();
        getline(cin, projectName);
    }
    
    void display() override {
        cout << "\n=== Manager-Employee Details ===\n";
        cout << "Employee ID: " << employeeId << endl;
        Person::display();
        cout << "Department: " << department << endl;
        cout << "Team Size: " << teamSize << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Current Project: " << projectName << endl;
    }
    
    int getEmployeeId() { return employeeId; }
    string getName() { return name; }
};

// Employee Database Management System
class EmployeeDatabase {
private:
    vector<ManagerEmployee> employees;
    
public:
    void addEmployee() {
        ManagerEmployee emp;
        cout << "\n=== Add New Employee ===\n";
        emp.inputDetails();
        employees.push_back(emp);
        cout << "\n✓ Employee added successfully!\n";
    }
    
    void displayAllEmployees() {
        if (employees.empty()) {
            cout << "\nNo employees in database!\n";
            return;
        }
        
        cout << "\n========== Employee Database ==========\n";
        cout << "Total Employees: " << employees.size() << "\n";
        
        for (size_t i = 0; i < employees.size(); i++) {
            cout << "\n--- Employee " << (i + 1) << " ---";
            employees[i].display();
        }
        cout << "=======================================\n";
    }
    
    void searchEmployee() {
        if (employees.empty()) {
            cout << "\nNo employees in database!\n";
            return;
        }
        
        int id;
        cout << "\nEnter Employee ID to search: ";
        cin >> id;
        
        bool found = false;
        for (size_t i = 0; i < employees.size(); i++) {
            if (employees[i].getEmployeeId() == id) {
                cout << "\n✓ Employee Found!";
                employees[i].display();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "\n✗ Employee with ID " << id << " not found!\n";
        }
    }
    
    void deleteEmployee() {
        if (employees.empty()) {
            cout << "\nNo employees in database!\n";
            return;
        }
        
        int id;
        cout << "\nEnter Employee ID to delete: ";
        cin >> id;
        
        for (size_t i = 0; i < employees.size(); i++) {
            if (employees[i].getEmployeeId() == id) {
                cout << "\nDeleting employee: " << employees[i].getName() << endl;
                employees.erase(employees.begin() + i);
                cout << "✓ Employee deleted successfully!\n";
                return;
            }
        }
        
        cout << "\n✗ Employee with ID " << id << " not found!\n";
    }
};

int main() {
    EmployeeDatabase db;
    int choice;
    
    cout << "===== Employee Database System =====\n";
    cout << "===== Using Virtual Base Class =====\n\n";
    
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }
        
        switch(choice) {
            case 1:
                db.addEmployee();
                break;
            case 2:
                db.displayAllEmployees();
                break;
            case 3:
                db.searchEmployee();
                break;
            case 4:
                db.deleteEmployee();
                break;
            case 5:
                cout << "\nExiting... Thank you!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while(choice != 5);
    
    return 0;
}
