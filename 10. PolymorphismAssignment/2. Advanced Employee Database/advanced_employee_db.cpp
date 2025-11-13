#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

// Virtual base class
class BasicInfo {
protected:
    string name;
    int id;
    
public:
    BasicInfo() : name(""), id(0) {}
    BasicInfo(string n, int i) : name(n), id(i) {}
    
    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
    
    virtual ~BasicInfo() {}
};

// Derived class with virtual inheritance
class PersonalDetails : virtual public BasicInfo {
protected:
    int age;
    string gender;
    string phone;
    
public:
    PersonalDetails() : age(0), gender(""), phone("") {}
    
    void display() override {
        BasicInfo::display();
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Derived class with virtual inheritance
class ProfessionalDetails : virtual public BasicInfo {
protected:
    string designation;
    string department;
    double experience;
    
public:
    ProfessionalDetails() : designation(""), department(""), experience(0.0) {}
    
    void display() override {
        BasicInfo::display();
        cout << "Designation: " << designation << endl;
        cout << "Department: " << department << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

// Employee class with multiple inheritance using virtual base class
class Employee : public PersonalDetails, public ProfessionalDetails {
private:
    double salary;
    string joiningDate;
    string email;
    
public:
    Employee() : salary(0.0), joiningDate(""), email("") {}
    
    void inputDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        // Clear newline then read full name
        cout << "Enter Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Gender: ";
        cin >> gender;

        cout << "Enter Phone: ";
        cin >> phone;

        // Clear leftover newline before reading full-line fields
        cout << "Enter Email: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, email);

        cout << "Enter Designation: ";
        getline(cin, designation);

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Experience (years): ";
        cin >> experience;

        cout << "Enter Salary: ";
        cin >> salary;

        cout << "Enter Joining Date (DD/MM/YYYY): ";
        cin >> joiningDate;
    }
    
    void display() override {
        cout << "\n========== Employee Details ==========\n";
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "Designation: " << designation << endl;
        cout << "Department: " << department << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
        cout << "Joining Date: " << joiningDate << endl;
        cout << "======================================\n";
    }
    
    int getId() { return id; }
    string getName() { return name; }
    string getDepartment() { return department; }
    double getSalary() { return salary; }
};

// Database Management System
class EmployeeDatabaseSystem {
private:
    vector<Employee*> employees;
    
public:
    ~EmployeeDatabaseSystem() {
        for (auto emp : employees) {
            delete emp;
        }
    }
    
    void addEmployee() {
        Employee* emp = new Employee();
        cout << "\n=== Add New Employee ===\n";
        emp->inputDetails();
        employees.push_back(emp);
        cout << "\n✓ Employee added successfully to database!\n";
    }
    
    void displayAll() {
        if (employees.empty()) {
            cout << "\n✗ Database is empty!\n";
            return;
        }
        
        cout << "\n========== EMPLOYEE DATABASE ==========\n";
        cout << "Total Employees: " << employees.size() << "\n";
        
        for (size_t i = 0; i < employees.size(); i++) {
            cout << "\n[Employee " << (i + 1) << "]";
            employees[i]->display();
        }
    }
    
    void searchById() {
        if (employees.empty()) {
            cout << "\n✗ Database is empty!\n";
            return;
        }
        
        int id;
        cout << "\nEnter Employee ID: ";
        cin >> id;
        
        for (auto emp : employees) {
            if (emp->getId() == id) {
                cout << "\n✓ Employee Found!";
                emp->display();
                return;
            }
        }
        
        cout << "\n✗ Employee not found!\n";
    }
    
    void displayByDepartment() {
        if (employees.empty()) {
            cout << "\n✗ Database is empty!\n";
            return;
        }
        
        string dept;
        cout << "\nEnter Department: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, dept);
        
        bool found = false;
        cout << "\n========== Employees in " << dept << " ==========\n";
        
        for (auto emp : employees) {
            if (emp->getDepartment() == dept) {
                emp->display();
                found = true;
            }
        }
        
        if (!found) {
            cout << "✗ No employees found in this department!\n";
        }
    }
    
    void calculateTotalSalary() {
        if (employees.empty()) {
            cout << "\n✗ Database is empty!\n";
            return;
        }
        
        double total = 0;
        for (auto emp : employees) {
            total += emp->getSalary();
        }
        
        cout << "\n========== Salary Statistics ==========\n";
        cout << "Total Employees: " << employees.size() << endl;
        cout << "Total Salary: $" << fixed << setprecision(2) << total << endl;
        cout << "Average Salary: $" << fixed << setprecision(2) << (total / employees.size()) << endl;
        cout << "======================================\n";
    }
};

int main() {
    EmployeeDatabaseSystem db;
    int choice;
    
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║  Employee Database Management System ║\n";
    cout << "║     Using Virtual Base Classes       ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    
    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Display by Department\n";
        cout << "5. Salary Statistics\n";
        cout << "6. Exit\n";
        cout << "==========================\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n✗ Invalid input! Try again.\n";
            continue;
        }
        
        switch(choice) {
            case 1:
                db.addEmployee();
                break;
            case 2:
                db.displayAll();
                break;
            case 3:
                db.searchById();
                break;
            case 4:
                db.displayByDepartment();
                break;
            case 5:
                db.calculateTotalSalary();
                break;
            case 6:
                cout << "\n✓ Exiting system. Goodbye!\n";
                break;
            default:
                cout << "\n✗ Invalid choice! Try again.\n";
        }
    } while(choice != 6);
    
    return 0;
}
