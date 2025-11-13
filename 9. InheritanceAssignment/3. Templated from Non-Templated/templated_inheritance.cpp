#include <iostream>
#include <string>
using namespace std;

// Non-templated base class
class Person {
protected:
    string name;
    int age;
    string address;
    
public:
    Person() : name(""), age(0), address("") {}
    
    Person(string n, int a, string addr) : name(n), age(a), address(addr) {}
    
    void setPersonDetails(string n, int a, string addr) {
        name = n;
        age = a;
        address = addr;
    }
    
    void displayPersonDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
    
    string getName() { return name; }
    int getAge() { return age; }
    string getAddress() { return address; }
};

// Templated derived class
template <typename T>
class Employee : public Person {
private:
    T employeeId;
    string department;
    T salary;
    
public:
    Employee() : Person(), employeeId(T()), department(""), salary(T()) {}
    
    Employee(string n, int a, string addr, T empId, string dept, T sal) 
        : Person(n, a, addr), employeeId(empId), department(dept), salary(sal) {}
    
    void setEmployeeDetails(T empId, string dept, T sal) {
        employeeId = empId;
        department = dept;
        salary = sal;
    }
    
    void inputDetails() {
        string n, addr, dept;
        int a;
        T empId, sal;
        
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, n);
        cout << "Enter Age: ";
        cin >> a;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, addr);
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Department: ";
        cin.ignore();
        getline(cin, dept);
        cout << "Enter Salary: ";
        cin >> sal;
        
        setPersonDetails(n, a, addr);
        setEmployeeDetails(empId, dept, sal);
    }
    
    void displayDetails() {
        cout << "\n=== Employee Details ===\n";
        displayPersonDetails();
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
    
    T getEmployeeId() { return employeeId; }
    string getDepartment() { return department; }
    T getSalary() { return salary; }
};

// Another templated derived class for Students
template <typename T1, typename T2>
class GraduateStudent : public Person {
private:
    T1 studentId;
    string course;
    T2 gpa;
    string university;
    
public:
    GraduateStudent() : Person(), studentId(T1()), course(""), gpa(T2()), university("") {}
    
    void setStudentDetails(T1 stuId, string crs, T2 g, string univ) {
        studentId = stuId;
        course = crs;
        gpa = g;
        university = univ;
    }
    
    void inputDetails() {
        string n, addr, crs, univ;
        int a;
        T1 stuId;
        T2 g;
        
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, n);
        cout << "Enter Age: ";
        cin >> a;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, addr);
        cout << "Enter Student ID: ";
        cin >> stuId;
        cout << "Enter Course: ";
        cin.ignore();
        getline(cin, crs);
        cout << "Enter GPA: ";
        cin >> g;
        cout << "Enter University: ";
        cin.ignore();
        getline(cin, univ);
        
        setPersonDetails(n, a, addr);
        setStudentDetails(stuId, crs, g, univ);
    }
    
    void displayDetails() {
        cout << "\n=== Graduate Student Details ===\n";
        displayPersonDetails();
        cout << "Student ID: " << studentId << endl;
        cout << "Course: " << course << endl;
        cout << "GPA: " << gpa << endl;
        cout << "University: " << university << endl;
    }
};

int main() {
    int choice;
    
    cout << "===== Templated Class Derived from Non-Templated Class =====\n\n";
    cout << "Select Option:\n";
    cout << "1. Employee (Template with int)\n";
    cout << "2. Employee (Template with string)\n";
    cout << "3. Graduate Student (Template with int and float)\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch(choice) {
        case 1: {
            Employee<int> emp;
            cout << "\n=== Enter Employee Details (ID: int, Salary: int) ===\n";
            emp.inputDetails();
            emp.displayDetails();
            break;
        }
        case 2: {
            Employee<string> emp;
            cout << "\n=== Enter Employee Details (ID: string, Salary: string) ===\n";
            emp.inputDetails();
            emp.displayDetails();
            break;
        }
        case 3: {
            GraduateStudent<int, float> student;
            cout << "\n=== Enter Graduate Student Details ===\n";
            student.inputDetails();
            student.displayDetails();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
    
    cout << "\n===== Demonstration Complete =====\n";
    
    return 0;
}
