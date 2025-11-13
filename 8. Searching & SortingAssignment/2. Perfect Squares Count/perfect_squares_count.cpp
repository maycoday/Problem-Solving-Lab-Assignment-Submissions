#include <iostream>
#include <cmath>
using namespace std;

// Method 1: Using square root - Most efficient
int countPerfectSquares_SquareRoot(int n) {
    if (n <= 1) {
        return 0;
    }
    
    // The count of perfect squares less than n is floor(sqrt(n-1))
    return (int)sqrt(n - 1);
}

// Method 2: Binary Search to find the answer
int countPerfectSquares_BinarySearch(int n) {
    if (n <= 1) {
        return 0;
    }
    
    int left = 1, right = n / 2;
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = (long long)mid * mid;
        
        if (square < n) {
            result = mid;  // mid is a valid answer
            left = mid + 1;  // Try to find larger
        } else {
            right = mid - 1;  // Try smaller values
        }
    }
    
    return result;
}

// Method 3: Iterative approach
int countPerfectSquares_Iterative(int n) {
    int count = 0;
    
    for (int i = 1; i * i < n; i++) {
        count++;
    }
    
    return count;
}

void displayPerfectSquares(int n, int limit = 20) {
    cout << "\nPerfect squares less than " << n << ":\n";
    
    int i = 1;
    int displayed = 0;
    
    while (i * i < n && displayed < limit) {
        cout << i << "² = " << (i * i) << endl;
        i++;
        displayed++;
    }
    
    if (i * i < n) {
        int remaining = countPerfectSquares_SquareRoot(n) - displayed;
        cout << "... (" << remaining << " more)\n";
    }
}

int main() {
    int n;
    
    cout << "Enter a number N: ";
    cin >> n;
    
    if (n < 1) {
        cout << "Please enter a positive integer!" << endl;
        return 0;
    }
    
    cout << "\n========================================\n";
    cout << "Sample Space S: {1, 4, 9, 16, 25, ...}\n";
    cout << "========================================\n";
    
    // Show some perfect squares
    if (n <= 500) {
        displayPerfectSquares(n);
    }
    
    // Calculate count using different methods
    int count1 = countPerfectSquares_SquareRoot(n);
    int count2 = countPerfectSquares_BinarySearch(n);
    int count3 = countPerfectSquares_Iterative(n);
    
    cout << "\n--- Results ---\n";
    cout << "Method 1 (Square Root):    " << count1 << endl;
    cout << "Method 2 (Binary Search):  " << count2 << endl;
    cout << "Method 3 (Iterative):      " << count3 << endl;
    
    cout << "\n✓ Answer: " << count1 << " integers in sample space S are less than " << n << endl;
    
    return 0;
}
