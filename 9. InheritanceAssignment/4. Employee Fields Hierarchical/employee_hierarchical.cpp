#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
protected:
    string name;
    int employeeId;
    int age;
    string gender;
    string email;
    
public:
    void getBasicDetails() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Employee ID: ";
        cin >> employeeId;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
        cout << "Enter Email: ";
        cin.ignore();
        getline(cin, email);
    }
    
    void displayBasicDetails() {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Email: " << email << endl;
    }
};

// Derived class 1: Software Engineer
class SoftwareEngineer : public Employee {
private:
    string programmingLanguage;
    int experienceYears;
    double salary;
    string project;
    
public:
    void getDetails() {
        cout << "\n=== Enter Software Engineer Details ===\n";
        getBasicDetails();
        cout << "Enter Primary Programming Language: ";
        cin.ignore();
        getline(cin, programmingLanguage);
        cout << "Enter Years of Experience: ";
        cin >> experienceYears;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Current Project: ";
        cin.ignore();
        getline(cin, project);
    }
    
    void displayDetails() {
        cout << "\n=== Software Engineer Details ===\n";
        displayBasicDetails();
        cout << "Field: Software Engineering\n";
        cout << "Programming Language: " << programmingLanguage << endl;
        cout << "Experience: " << experienceYears << " years" << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Current Project: " << project << endl;
    }
};

// Derived class 2: Marketing Manager
class MarketingManager : public Employee {
private:
    string specialization;
    int teamSize;
    double salary;
    string currentCampaign;
    
public:
    void getDetails() {
        cout << "\n=== Enter Marketing Manager Details ===\n";
        getBasicDetails();
        cout << "Enter Specialization: ";
        cin.ignore();
        getline(cin, specialization);
        cout << "Enter Team Size: ";
        cin >> teamSize;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Current Campaign: ";
        cin.ignore();
        getline(cin, currentCampaign);
    }
    
    void displayDetails() {
        cout << "\n=== Marketing Manager Details ===\n";
        displayBasicDetails();
        cout << "Field: Marketing\n";
        cout << "Specialization: " << specialization << endl;
        cout << "Team Size: " << teamSize << " members" << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Current Campaign: " << currentCampaign << endl;
    }
};

// Derived class 3: HR Manager
class HRManager : public Employee {
private:
    string department;
    int employeesManaged;
    double salary;
    string hrPolicy;
    
public:
    void getDetails() {
        cout << "\n=== Enter HR Manager Details ===\n";
        getBasicDetails();
        cout << "Enter Department: ";
        cin.ignore();
        getline(cin, department);
        cout << "Enter Number of Employees Managed: ";
        cin >> employeesManaged;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Recent HR Policy: ";
        cin.ignore();
        getline(cin, hrPolicy);
    }
    
    void displayDetails() {
        cout << "\n=== HR Manager Details ===\n";
        displayBasicDetails();
        cout << "Field: Human Resources\n";
        cout << "Department: " << department << endl;
        cout << "Employees Managed: " << employeesManaged << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Recent HR Policy: " << hrPolicy << endl;
    }
};

// Derived class 4: Finance Analyst
class FinanceAnalyst : public Employee {
private:
    string certification;
    int projectsCompleted;
    double salary;
    string currentAnalysis;
    
public:
    void getDetails() {
        cout << "\n=== Enter Finance Analyst Details ===\n";
        getBasicDetails();
        cout << "Enter Certification (e.g., CFA, CA): ";
        cin.ignore();
        getline(cin, certification);
        cout << "Enter Projects Completed: ";
        cin >> projectsCompleted;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Current Analysis Topic: ";
        cin.ignore();
        getline(cin, currentAnalysis);
    }
    
    void displayDetails() {
        cout << "\n=== Finance Analyst Details ===\n";
        displayBasicDetails();
        cout << "Field: Finance\n";
        cout << "Certification: " << certification << endl;
        cout << "Projects Completed: " << projectsCompleted << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Current Analysis: " << currentAnalysis << endl;
    }
};

int main() {
    int choice;
    
    cout << "====== Employee Management System ======\n";
    cout << "====== Hierarchical Inheritance ======\n\n";
    
    cout << "Select Employee Field:\n";
    cout << "1. Software Engineering\n";
    cout << "2. Marketing\n";
    cout << "3. Human Resources\n";
    cout << "4. Finance\n";
    cout << "Enter your choice: ";
    cin >> choice;
    
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice!" << endl;
        return 0;
    }
    
    switch(choice) {
        case 1: {
            SoftwareEngineer se;
            se.getDetails();
            se.displayDetails();
            break;
        }
        case 2: {
            MarketingManager mm;
            mm.getDetails();
            mm.displayDetails();
            break;
        }
        case 3: {
            HRManager hr;
            hr.getDetails();
            hr.displayDetails();
            break;
        }
        case 4: {
            FinanceAnalyst fa;
            fa.getDetails();
            fa.displayDetails();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}
