#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

class WordCounter {
private:
    string filename;
    
    // Function to convert string to lowercase
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
    
    // Function to remove punctuation from word
    string removePunctuation(string word) {
        string result = "";
        for (char c : word) {
            if (isalnum(c)) {
                result += c;
            }
        }
        return result;
    }
    
public:
    WordCounter(string fname) : filename(fname) {}
    
    // Create a sample file with content
    void createSampleFile() {
        ofstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error creating file!\n";
            return;
        }
        
        cout << "\nEnter text to write to file (type 'END' on a new line to finish):\n";
        cin.ignore();
        
        string line;
        while (getline(cin, line)) {
            if (line == "END") break;
            file << line << endl;
        }
        
        file.close();
        cout << "\n✓ File created successfully!\n";
    }
    
    // Count occurrence of a specific word
    int countSpecificWord(string searchWord) {
        ifstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error: File does not exist!\n";
            return -1;
        }
        
        searchWord = toLowerCase(removePunctuation(searchWord));
        int count = 0;
        string word;
        
        while (file >> word) {
            word = toLowerCase(removePunctuation(word));
            if (word == searchWord) {
                count++;
            }
        }
        
        file.close();
        return count;
    }
    
    // Count all words and their frequencies
    void countAllWords() {
        ifstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error: File does not exist!\n";
            return;
        }
        
        map<string, int> wordFrequency;
        string word;
        
        while (file >> word) {
            word = toLowerCase(removePunctuation(word));
            if (!word.empty()) {
                wordFrequency[word]++;
            }
        }
        
        file.close();
        
        if (wordFrequency.empty()) {
            cout << "\n✗ No words found in file!\n";
            return;
        }
        
        cout << "\n========== Word Frequency ==========\n";
        cout << "Total unique words: " << wordFrequency.size() << "\n";
        cout << "====================================\n";
        
        for (const auto& pair : wordFrequency) {
            cout << pair.first << " : " << pair.second << " time(s)\n";
        }
        cout << "====================================\n";
    }
    
    // Display file content
    void displayFileContent() {
        ifstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error: File does not exist!\n";
            return;
        }
        
        cout << "\n========== File Content ==========\n";
        string line;
        int lineNum = 1;
        
        while (getline(file, line)) {
            cout << lineNum++ << ": " << line << endl;
        }
        
        cout << "==================================\n";
        file.close();
    }
    
    // Find words with specific occurrence count
    void findWordsByCount(int targetCount) {
        ifstream file(filename);
        
        if (!file) {
            cout << "\n✗ Error: File does not exist!\n";
            return;
        }
        
        map<string, int> wordFrequency;
        string word;
        
        while (file >> word) {
            word = toLowerCase(removePunctuation(word));
            if (!word.empty()) {
                wordFrequency[word]++;
            }
        }
        
        file.close();
        
        cout << "\nWords that appear exactly " << targetCount << " time(s):\n";
        cout << "----------------------------------------\n";
        
        bool found = false;
        for (const auto& pair : wordFrequency) {
            if (pair.second == targetCount) {
                cout << pair.first << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "No words found with that frequency.\n";
        }
        cout << "----------------------------------------\n";
    }
};

int main() {
    string filename;
    int choice;
    
    cout << "╔═══════════════════════════════════════╗\n";
    cout << "║  Word Occurrence Counter Program      ║\n";
    cout << "║  Using File Handling                  ║\n";
    cout << "╚═══════════════════════════════════════╝\n\n";
    
    cout << "Enter filename: ";
    getline(cin, filename);
    
    WordCounter wc(filename);
    
    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Create/Write File\n";
        cout << "2. Display File Content\n";
        cout << "3. Count Specific Word\n";
        cout << "4. Count All Words\n";
        cout << "5. Find Words by Occurrence\n";
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
            case 1: {
                wc.createSampleFile();
                break;
            }
            case 2: {
                wc.displayFileContent();
                break;
            }
            case 3: {
                string searchWord;
                cout << "\nEnter word to search: ";
                cin >> searchWord;
                
                int count = wc.countSpecificWord(searchWord);
                if (count >= 0) {
                    cout << "\n========== Result ==========\n";
                    cout << "Word: \"" << searchWord << "\"\n";
                    cout << "Occurrences: " << count << " time(s)\n";
                    cout << "============================\n";
                }
                break;
            }
            case 4: {
                wc.countAllWords();
                break;
            }
            case 5: {
                int targetCount;
                cout << "\nEnter occurrence count to search for: ";
                cin >> targetCount;
                wc.findWordsByCount(targetCount);
                break;
            }
            case 6: {
                cout << "\n✓ Exiting program. Goodbye!\n";
                break;
            }
            default: {
                cout << "\n✗ Invalid choice! Please try again.\n";
            }
        }
    } while(choice != 6);
    
    return 0;
}
