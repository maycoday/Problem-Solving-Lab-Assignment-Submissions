#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to store student data
struct Student {
    int rollNumber;
    string name;
    float marks;
    char grade;
};

// Class to store employee data
class Employee {
public:
    int empId;
    string name;
    double salary;
    string department;
    
    Employee() : empId(0), name(""), salary(0.0), department("") {}
    
    Employee(int id, string n, double sal, string dept) 
        : empId(id), name(n), salary(sal), department(dept) {}
    
    void display() {
        cout << "Employee ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Department: " << department << endl;
    }
};

class FileHandler {
private:
    string filename;
    
public:
    FileHandler(string fname) : filename(fname) {}
    
    // Write primitive variables to file
    void writePrimitiveVariables() {
        ofstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error creating file!\n";
            return;
        }
        
        // Primitive variables
        int age;
        float height;
        double salary;
        char grade;
        string name;
        
        cout << "\n=== Enter Data ===\n";
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Height (in meters): ";
        cin >> height;
        cout << "Enter Salary: ";
        cin >> salary;
        cout << "Enter Grade: ";
        cin >> grade;
        
        // Write to file
        file << name << endl;
        file << age << endl;
        file << height << endl;
        file << salary << endl;
        file << grade << endl;
        
        file.close();
        cout << "\n✓ Primitive variables written to file successfully!\n";
    }
    
    // Read primitive variables from file
    void readPrimitiveVariables() {
        ifstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error: File does not exist!\n";
            return;
        }
        
        string name;
        int age;
        float height;
        double salary;
        char grade;
        
        // Read from file
        getline(file, name);
        file >> age;
        file >> height;
        file >> salary;
        file >> grade;
        
        file.close();
        
        cout << "\n========== Data Read from File ==========\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << " meters" << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Grade: " << grade << endl;
        cout << "=========================================\n";
    }
    
    // Write structure data to file
    void writeStructureData() {
        ofstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error creating file!\n";
            return;
        }
        
        Student student;
        
        cout << "\n=== Enter Student Data ===\n";
        cout << "Enter Roll Number: ";
        cin >> student.rollNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, student.name);
        cout << "Enter Marks: ";
        cin >> student.marks;
        cout << "Enter Grade: ";
        cin >> student.grade;
        
        // Write structure data to file
        file << student.rollNumber << endl;
        file << student.name << endl;
        file << student.marks << endl;
        file << student.grade << endl;
        
        file.close();
        cout << "\n✓ Structure data written to file successfully!\n";
    }
    
    // Read structure data from file
    void readStructureData() {
        ifstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error: File does not exist!\n";
            return;
        }
        
        Student student;
        
        file >> student.rollNumber;
        file.ignore();
        getline(file, student.name);
        file >> student.marks;
        file >> student.grade;
        
        file.close();
        
        cout << "\n========== Student Data from File ==========\n";
        cout << "Roll Number: " << student.rollNumber << endl;
        cout << "Name: " << student.name << endl;
        cout << "Marks: " << student.marks << endl;
        cout << "Grade: " << student.grade << endl;
        cout << "============================================\n";
    }
    
    // Write class object data to file
    void writeClassObjectData() {
        ofstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error creating file!\n";
            return;
        }
        
        Employee emp;
        
        cout << "\n=== Enter Employee Data ===\n";
        cout << "Enter Employee ID: ";
        cin >> emp.empId;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, emp.name);
        cout << "Enter Salary: ";
        cin >> emp.salary;
        cout << "Enter Department: ";
        cin.ignore();
        getline(cin, emp.department);
        
        // Write object data to file
        file << emp.empId << endl;
        file << emp.name << endl;
        file << emp.salary << endl;
        file << emp.department << endl;
        
        file.close();
        cout << "\n✓ Class object data written to file successfully!\n";
    }
    
    // Read class object data from file
    void readClassObjectData() {
        ifstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error: File does not exist!\n";
            return;
        }
        
        Employee emp;
        
        file >> emp.empId;
        file.ignore();
        getline(file, emp.name);
        file >> emp.salary;
        file.ignore();
        getline(file, emp.department);
        
        file.close();
        
        cout << "\n========== Employee Data from File ==========\n";
        emp.display();
        cout << "=============================================\n";
    }
    
    // Write binary data
    void writeBinaryData() {
        ofstream file(filename, ios::binary);
        
        if (!file) {
            cout << "\n✗ Error creating file!\n";
            return;
        }
        
        int numbers[5];
        cout << "\n=== Enter 5 integers ===\n";
        for (int i = 0; i < 5; i++) {
            cout << "Number " << (i + 1) << ": ";
            cin >> numbers[i];
        }
        
        // Write binary data
        file.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
        file.close();
        
        cout << "\n✓ Binary data written to file successfully!\n";
    }
    
    // Read binary data
    void readBinaryData() {
        ifstream file(filename, ios::binary);
        
        if (!file) {
            cout << "\n✗ Error: File does not exist!\n";
            return;
        }
        
        int numbers[5];
        
        // Read binary data
        file.read(reinterpret_cast<char*>(numbers), sizeof(numbers));
        file.close();
        
        cout << "\n========== Binary Data from File ==========\n";
        for (int i = 0; i < 5; i++) {
            cout << "Number " << (i + 1) << ": " << numbers[i] << endl;
        }
        cout << "===========================================\n";
    }
};

int main() {
    string filename;
    int choice;
    
    cout << "╔═══════════════════════════════════════╗\n";
    cout << "║  Read/Write Variables from/to File    ║\n";
    cout << "║  Demonstration Program                ║\n";
    cout << "╚═══════════════════════════════════════╝\n\n";
    
    cout << "Enter filename: ";
    getline(cin, filename);
    
    FileHandler fh(filename);
    
    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Write Primitive Variables\n";
        cout << "2. Read Primitive Variables\n";
        cout << "3. Write Structure Data\n";
        cout << "4. Read Structure Data\n";
        cout << "5. Write Class Object Data\n";
        cout << "6. Read Class Object Data\n";
        cout << "7. Write Binary Data\n";
        cout << "8. Read Binary Data\n";
        cout << "9. Exit\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\n✗ Invalid input! Please enter a number.\n";
            continue;
        }
        
        switch(choice) {
            case 1:
                fh.writePrimitiveVariables();
                break;
            case 2:
                fh.readPrimitiveVariables();
                break;
            case 3:
                fh.writeStructureData();
                break;
            case 4:
                fh.readStructureData();
                break;
            case 5:
                fh.writeClassObjectData();
                break;
            case 6:
                fh.readClassObjectData();
                break;
            case 7:
                fh.writeBinaryData();
                break;
            case 8:
                fh.readBinaryData();
                break;
            case 9:
                cout << "\n✓ Exiting program. Goodbye!\n";
                break;
            default:
                cout << "\n✗ Invalid choice! Please try again.\n";
        }
    } while(choice != 9);
    
    return 0;
}
