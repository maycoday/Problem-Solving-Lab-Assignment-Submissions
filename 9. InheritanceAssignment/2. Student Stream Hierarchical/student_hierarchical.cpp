#include <iostream>
#include <string>
using namespace std;

// Base class
class Student {
protected:
    string name;
    int rollNumber;
    int age;
    string gender;
    
public:
    void getBasicDetails() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
    }
    
    void displayBasicDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

// Derived class 1: Science Stream
class ScienceStudent : public Student {
private:
    int physicsMarks;
    int chemistryMarks;
    int mathsMarks;
    string lab;
    
public:
    void getDetails() {
        cout << "\n=== Enter Science Stream Student Details ===\n";
        getBasicDetails();
        cout << "Enter Physics Marks: ";
        cin >> physicsMarks;
        cout << "Enter Chemistry Marks: ";
        cin >> chemistryMarks;
        cout << "Enter Maths Marks: ";
        cin >> mathsMarks;
        cout << "Enter Lab Preference: ";
        cin.ignore();
        getline(cin, lab);
    }
    
    void displayDetails() {
        cout << "\n=== Science Stream Student ===\n";
        displayBasicDetails();
        cout << "Stream: Science\n";
        cout << "Physics Marks: " << physicsMarks << endl;
        cout << "Chemistry Marks: " << chemistryMarks << endl;
        cout << "Maths Marks: " << mathsMarks << endl;
        cout << "Total Marks: " << (physicsMarks + chemistryMarks + mathsMarks) << "/300" << endl;
        cout << "Percentage: " << ((physicsMarks + chemistryMarks + mathsMarks) / 3.0) << "%" << endl;
        cout << "Lab Preference: " << lab << endl;
    }
};

// Derived class 2: Commerce Stream
class CommerceStudent : public Student {
private:
    int accountsMarks;
    int economicsMarks;
    int businessStudiesMarks;
    string internship;
    
public:
    void getDetails() {
        cout << "\n=== Enter Commerce Stream Student Details ===\n";
        getBasicDetails();
        cout << "Enter Accounts Marks: ";
        cin >> accountsMarks;
        cout << "Enter Economics Marks: ";
        cin >> economicsMarks;
        cout << "Enter Business Studies Marks: ";
        cin >> businessStudiesMarks;
        cout << "Enter Internship Details: ";
        cin.ignore();
        getline(cin, internship);
    }
    
    void displayDetails() {
        cout << "\n=== Commerce Stream Student ===\n";
        displayBasicDetails();
        cout << "Stream: Commerce\n";
        cout << "Accounts Marks: " << accountsMarks << endl;
        cout << "Economics Marks: " << economicsMarks << endl;
        cout << "Business Studies Marks: " << businessStudiesMarks << endl;
        cout << "Total Marks: " << (accountsMarks + economicsMarks + businessStudiesMarks) << "/300" << endl;
        cout << "Percentage: " << ((accountsMarks + economicsMarks + businessStudiesMarks) / 3.0) << "%" << endl;
        cout << "Internship: " << internship << endl;
    }
};

// Derived class 3: Arts Stream
class ArtsStudent : public Student {
private:
    int historyMarks;
    int politicalScienceMarks;
    int englishMarks;
    string extraCurricular;
    
public:
    void getDetails() {
        cout << "\n=== Enter Arts Stream Student Details ===\n";
        getBasicDetails();
        cout << "Enter History Marks: ";
        cin >> historyMarks;
        cout << "Enter Political Science Marks: ";
        cin >> politicalScienceMarks;
        cout << "Enter English Marks: ";
        cin >> englishMarks;
        cout << "Enter Extra-Curricular Activity: ";
        cin.ignore();
        getline(cin, extraCurricular);
    }
    
    void displayDetails() {
        cout << "\n=== Arts Stream Student ===\n";
        displayBasicDetails();
        cout << "Stream: Arts\n";
        cout << "History Marks: " << historyMarks << endl;
        cout << "Political Science Marks: " << politicalScienceMarks << endl;
        cout << "English Marks: " << englishMarks << endl;
        cout << "Total Marks: " << (historyMarks + politicalScienceMarks + englishMarks) << "/300" << endl;
        cout << "Percentage: " << ((historyMarks + politicalScienceMarks + englishMarks) / 3.0) << "%" << endl;
        cout << "Extra-Curricular: " << extraCurricular << endl;
    }
};

int main() {
    int choice;
    
    cout << "====== Student Management System ======\n";
    cout << "====== Hierarchical Inheritance ======\n\n";
    
    cout << "Select Student Stream:\n";
    cout << "1. Science Stream\n";
    cout << "2. Commerce Stream\n";
    cout << "3. Arts Stream\n";
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
            ScienceStudent sciStudent;
            sciStudent.getDetails();
            sciStudent.displayDetails();
            break;
        }
        case 2: {
            CommerceStudent comStudent;
            comStudent.getDetails();
            comStudent.displayDetails();
            break;
        }
        case 3: {
            ArtsStudent artsStudent;
            artsStudent.getDetails();
            artsStudent.displayDetails();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
}
