#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class FileManager {
private:
    string filename;
    
public:
    FileManager(string fname) : filename(fname) {}
    
    // Add content to file (overwrite existing content)
    void addContent() {
        ofstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error: Could not create file!\n";
            return;
        }
        
        string content;
        cout << "\nEnter content to add to file (type 'END' on a new line to finish):\n";
        cin.ignore();
        
        string line;
        while (getline(cin, line)) {
            if (line == "END") break;
            content += line + "\n";
        }
        
        file << content;
        file.close();
        cout << "\n✓ Content added successfully to file: " << filename << endl;
    }
    
    // Modify content in file (replace specific text)
    void modifyContent() {
        ifstream inFile(filename);
        
        if (!inFile) {
            cout << "\n✗ Error: File does not exist!\n";
            return;
        }
        
        // Read entire file content
        string content, line;
        while (getline(inFile, line)) {
            content += line + "\n";
        }
        inFile.close();
        
        if (content.empty()) {
            cout << "\n✗ File is empty! Nothing to modify.\n";
            return;
        }
        
        cout << "\nCurrent file content:\n";
        cout << "--------------------\n";
        cout << content;
        cout << "--------------------\n";
        
        string searchStr, replaceStr;
        cout << "\nEnter text to search: ";
        cin.ignore();
        getline(cin, searchStr);
        cout << "Enter replacement text: ";
        getline(cin, replaceStr);
        
        // Find and replace
        size_t pos = content.find(searchStr);
        if (pos != string::npos) {
            content.replace(pos, searchStr.length(), replaceStr);
            
            // Write modified content back to file
            ofstream outFile(filename);
            outFile << content;
            outFile.close();
            
            cout << "\n✓ Content modified successfully!\n";
        } else {
            cout << "\n✗ Text not found in file!\n";
        }
    }
    
    // Append content to file
    void appendContent() {
        ofstream file(filename, ios::app);
        
        if (!file) {
            cout << "\n✗ Error: Could not open file!\n";
            return;
        }
        
        string content;
        cout << "\nEnter content to append (type 'END' on a new line to finish):\n";
        cin.ignore();
        
        string line;
        while (getline(cin, line)) {
            if (line == "END") break;
            content += line + "\n";
        }
        
        file << content;
        file.close();
        cout << "\n✓ Content appended successfully to file: " << filename << endl;
    }
    
    // Display file content
    void displayContent() {
        ifstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error: File does not exist!\n";
            return;
        }
        
        string line;
        int lineNum = 1;
        bool isEmpty = true;
        
        cout << "\n========== File Content ==========\n";
        cout << "File: " << filename << "\n";
        cout << "==================================\n";
        
        while (getline(file, line)) {
            cout << lineNum++ << ": " << line << endl;
            isEmpty = false;
        }
        
        if (isEmpty) {
            cout << "(File is empty)\n";
        }
        
        cout << "==================================\n";
        file.close();
    }
    
    // Display file info
    void displayFileInfo() {
        ifstream file(filename);
        
        if (!file) {
            cout << "\n✗ File does not exist!\n";
            return;
        }
        
        string line;
        int lines = 0, words = 0, characters = 0;
        
        while (getline(file, line)) {
            lines++;
            characters += line.length();
            
            // Count words
            bool inWord = false;
            for (char c : line) {
                if (isspace(c)) {
                    inWord = false;
                } else if (!inWord) {
                    words++;
                    inWord = true;
                }
            }
        }
        
        file.close();
        
        cout << "\n========== File Statistics ==========\n";
        cout << "Filename: " << filename << endl;
        cout << "Total Lines: " << lines << endl;
        cout << "Total Words: " << words << endl;
        cout << "Total Characters: " << characters << endl;
        cout << "====================================\n";
    }
};

int main() {
    string filename;
    int choice;
    
    cout << "╔═══════════════════════════════════════╗\n";
    cout << "║  File Handling Operations Program     ║\n";
    cout << "║  Menu Driven System                   ║\n";
    cout << "╚═══════════════════════════════════════╝\n\n";
    
    cout << "Enter filename to work with: ";
    getline(cin, filename);
    
    FileManager fm(filename);
    
    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Content (Overwrite)\n";
        cout << "2. Modify Content\n";
        cout << "3. Append Content\n";
        cout << "4. Display Content\n";
        cout << "5. File Statistics\n";
        cout << "6. Exit\n";
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
                fm.addContent();
                break;
            case 2:
                fm.modifyContent();
                break;
            case 3:
                fm.appendContent();
                break;
            case 4:
                fm.displayContent();
                break;
            case 5:
                fm.displayFileInfo();
                break;
            case 6:
                cout << "\n✓ Exiting program. Goodbye!\n";
                break;
            default:
                cout << "\n✗ Invalid choice! Please try again.\n";
        }
    } while(choice != 6);
    
    return 0;
}
