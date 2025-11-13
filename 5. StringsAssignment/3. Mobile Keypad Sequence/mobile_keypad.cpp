#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string getKeypadSequence(string sentence) {
    // Mobile keypad mapping
    string keypad[] = {
        "2",    // A
        "22",   // B
        "222",  // C
        "3",    // D
        "33",   // E
        "333",  // F
        "4",    // G
        "44",   // H
        "444",  // I
        "5",    // J
        "55",   // K
        "555",  // L
        "6",    // M
        "66",   // N
        "666",  // O
        "7",    // P
        "77",   // Q
        "777",  // R
        "7777", // S
        "8",    // T
        "88",   // U
        "888",  // V
        "9",    // W
        "99",   // X
        "999",  // Y
        "9999"  // Z
    };
    
    string result = "";
    
    for (int i = 0; i < sentence.length(); i++) {
        char ch = sentence[i];
        
        if (ch == ' ') {
            result += "0";
        } else if (isalpha(ch)) {
            // Convert to uppercase
            ch = toupper(ch);
            // Get the keypad sequence for this character
            result += keypad[ch - 'A'];
        }
        // Ignore non-alphabetic and non-space characters
    }
    
    return result;
}

int main() {
    string sentence;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    string keypadSequence = getKeypadSequence(sentence);
    
    cout << "\nOriginal sentence: " << sentence << endl;
    cout << "Mobile keypad sequence: " << keypadSequence << endl;
    
    // Display the keypad reference
    cout << "\n--- Mobile Keypad Reference ---\n";
    cout << "2: ABC\n";
    cout << "3: DEF\n";
    cout << "4: GHI\n";
    cout << "5: JKL\n";
    cout << "6: MNO\n";
    cout << "7: PQRS\n";
    cout << "8: TUV\n";
    cout << "9: WXYZ\n";
    cout << "0: SPACE\n";
    
    return 0;
}
