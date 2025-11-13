#include <iostream>
using namespace std;

// Function to count numbers where n + x = n ^ x
int countNumbers(int n) {
    int count = 0;
    
    // For n + x = n ^ x to be true:
    // n & x must be 0 (no common set bits)
    // This means x can only have bits set where n has 0 bits
    
    // Count the number of unset bits (0 bits) in n
    int unsetBits = 0;
    int temp = n;
    int bitPosition = 0;
    
    // Find the position of the most significant bit
    int msb = 0;
    int n_copy = n;
    while (n_copy > 0) {
        msb++;
        n_copy >>= 1;
    }
    
    // Count unset bits in n (up to MSB position)
    for (int i = 0; i < msb; i++) {
        if ((n & (1 << i)) == 0) {
            unsetBits++;
        }
    }
    
    // The count of valid x values is 2^(unset_bits)
    // Because each unset bit position can be either 0 or 1 in x
    count = 1 << unsetBits;  // 2^unsetBits
    
    return count;
}

// Function to verify and display valid numbers
void displayValidNumbers(int n) {
    cout << "\nValid numbers (x) where " << n << " + x = " << n << " ^ x:\n";
    int count = 0;
    
    // We only need to check up to n
    for (int x = 0; x <= n; x++) {
        if ((n + x) == (n ^ x)) {
            cout << "x = " << x;
            
            // Show binary representation
            cout << " (Binary: ";
            for (int i = 15; i >= 0; i--) {
                if (i < 8 || (x >> i) > 0 || (n >> i) > 0) {
                    cout << ((x >> i) & 1);
                }
            }
            cout << ")";
            
            // Verify
            cout << " -> " << n << " + " << x << " = " << (n + x);
            cout << ", " << n << " ^ " << x << " = " << (n ^ x) << endl;
            
            count++;
        }
    }
    cout << "\nTotal count: " << count << endl;
}

int main() {
    int n;
    
    cout << "Enter a number n: ";
    cin >> n;
    
    if (n < 0) {
        cout << "Please enter a non-negative number!" << endl;
        return 0;
    }
    
    // Display binary representation of n
    cout << "\nBinary representation of " << n << ": ";
    for (int i = 15; i >= 0; i--) {
        if (i < 8 || (n >> i) > 0) {
            cout << ((n >> i) & 1);
        }
    }
    cout << endl;
    
    // Count using formula
    int result = countNumbers(n);
    cout << "\nCount of numbers (x) where n + x = n ^ x: " << result << endl;
    
    // Display valid numbers if n is small
    if (n <= 100) {
        displayValidNumbers(n);
    }
    
    // Explanation
    cout << "\n--- Explanation ---\n";
    cout << "For n + x = n ^ x to be true:\n";
    cout << "- n & x must equal 0 (no common set bits)\n";
    cout << "- x can only have bits set where n has 0 bits\n";
    cout << "- Count = 2^(number of unset bits in n)\n";
    
    return 0;
}
