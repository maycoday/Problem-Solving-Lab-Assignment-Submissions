#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isValidShuffle(string str1, string str2, string result) {
    // Check if lengths match
    if (str1.length() + str2.length() != result.length()) {
        return false;
    }
    
    // Create a combined string of str1 and str2
    string combined = str1 + str2;
    
    // Sort both the combined string and result string
    sort(combined.begin(), combined.end());
    sort(result.begin(), result.end());
    
    // If sorted strings are equal, result is a valid shuffle
    return combined == result;
}

bool isValidShuffleOrder(string str1, string str2, string result) {
    // Check if lengths match
    if (str1.length() + str2.length() != result.length()) {
        return false;
    }
    
    int i = 0, j = 0, k = 0;
    
    // Check if result maintains the order of characters from str1 and str2
    while (k < (int)result.length()) {
        if (i < (int)str1.length() && str1[i] == result[k]) {
            i++;
        } else if (j < (int)str2.length() && str2[j] == result[k]) {
            j++;
        } else {
            return false;
        }
        k++;
    }
    
    // Check if all characters from both strings are used
    return (i == (int)str1.length() && j == (int)str2.length());
}

int main() {
    string str1, str2, result;
    
    cout << "Enter first string: ";
    cin >> str1;
    
    cout << "Enter second string: ";
    cin >> str2;
    
    cout << "Enter result string to check: ";
    cin >> result;
    
    cout << "\n--- Method 1: Character frequency check ---\n";
    if (isValidShuffle(str1, str2, result)) {
        cout << "\"" << result << "\" is a valid shuffle of \"" << str1 << "\" and \"" << str2 << "\"\n";
    } else {
        cout << "\"" << result << "\" is NOT a valid shuffle of \"" << str1 << "\" and \"" << str2 << "\"\n";
    }
    
    cout << "\n--- Method 2: Order-preserving check ---\n";
    if (isValidShuffleOrder(str1, str2, result)) {
        cout << "\"" << result << "\" is a valid order-preserving shuffle of \"" << str1 << "\" and \"" << str2 << "\"\n";
    } else {
        cout << "\"" << result << "\" is NOT a valid order-preserving shuffle of \"" << str1 << "\" and \"" << str2 << "\"\n";
    }
    
    return 0;
}
