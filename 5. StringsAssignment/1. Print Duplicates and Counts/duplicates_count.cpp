#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void printDuplicates(string str) {
    unordered_map<char, int> charCount;
    
    // Count frequency of each character
    for (char ch : str) {
        charCount[ch]++;
    }
    
    cout << "Duplicate characters and their counts:\n";
    bool hasDuplicates = false;
    
    // Print characters that appear more than once
    for (auto it : charCount) {
        if (it.second > 1) {
            cout << "'" << it.first << "' : " << it.second << " times\n";
            hasDuplicates = true;
        }
    }
    
    if (!hasDuplicates) {
        cout << "No duplicate characters found.\n";
    }
}

int main() {
    string input;
    
    cout << "Enter a string: ";
    getline(cin, input);
    
    printDuplicates(input);
    
    return 0;
}
