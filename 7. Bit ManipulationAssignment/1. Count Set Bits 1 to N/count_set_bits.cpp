#include <iostream>
using namespace std;

// Function to count set bits in a single number
int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += (num & 1);  // Check if last bit is set
        num >>= 1;           // Right shift by 1
    }
    return count;
}

// Method 1: Brute Force - Count set bits for each number
int totalSetBits_BruteForce(int n) {
    int totalCount = 0;
    for (int i = 1; i <= n; i++) {
        totalCount += countSetBits(i);
    }
    return totalCount;
}

// Method 2: Optimized approach using bit position pattern
int totalSetBits_Optimized(int n) {
    int totalCount = 0;
    int powerOf2 = 1;
    
    while (powerOf2 <= n) {
        // Total pairs of 0s and 1s
        int totalPairs = (n + 1) / (powerOf2 * 2);
        totalCount += totalPairs * powerOf2;
        
        // Remaining numbers
        int remaining = (n + 1) % (powerOf2 * 2);
        if (remaining > powerOf2) {
            totalCount += (remaining - powerOf2);
        }
        
        powerOf2 <<= 1;  // Multiply by 2
    }
    
    return totalCount;
}

int main() {
    int n;
    
    cout << "Enter a number N: ";
    cin >> n;
    
    if (n < 1) {
        cout << "Please enter a positive number!" << endl;
        return 0;
    }
    
    cout << "\n--- Counting set bits from 1 to " << n << " ---\n\n";
    
    // Show bit representation for small numbers
    if (n <= 20) {
        cout << "Binary representations:\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " = ";
            // Print binary representation
            for (int j = 7; j >= 0; j--) {
                cout << ((i >> j) & 1);
            }
            cout << " (Set bits: " << countSetBits(i) << ")\n";
        }
        cout << endl;
    }
    
    // Calculate total set bits
    int result1 = totalSetBits_BruteForce(n);
    int result2 = totalSetBits_Optimized(n);
    
    cout << "Total count of set bits (Method 1 - Brute Force): " << result1 << endl;
    cout << "Total count of set bits (Method 2 - Optimized): " << result2 << endl;
    
    return 0;
}
