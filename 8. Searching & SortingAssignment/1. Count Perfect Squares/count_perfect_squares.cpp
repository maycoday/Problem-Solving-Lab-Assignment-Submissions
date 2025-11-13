#include <iostream>
#include <cmath>
using namespace std;

// Method 1: Using square root
int countPerfectSquares_Method1(int n) {
    if (n <= 1) {
        return 0;
    }
    
    // Find the square root of (n-1) and floor it
    // This gives us the count of perfect squares less than n
    int count = (int)sqrt(n - 1);
    
    return count;
}

// Method 2: Binary Search approach
int countPerfectSquares_Method2(int n) {
    if (n <= 1) {
        return 0;
    }
    
    int low = 1, high = n - 1;
    int count = 0;
    
    // Binary search to find the largest number whose square is less than n
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long square = (long long)mid * mid;
        
        if (square < n) {
            count = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return count;
}

// Method 3: Linear counting (for verification)
int countPerfectSquares_Method3(int n) {
    int count = 0;
    int i = 1;
    
    while (i * i < n) {
        count++;
        i++;
    }
    
    return count;
}

int main() {
    int n;
    
    cout << "Enter a number N: ";
    cin >> n;
    
    if (n < 1) {
        cout << "Please enter a positive number!" << endl;
        return 0;
    }
    
    cout << "\n--- Perfect Squares Less Than " << n << " ---\n\n";
    
    // Display perfect squares if n is reasonable
    if (n <= 200) {
        cout << "Perfect squares in sample space S (less than " << n << "):\n";
        int i = 1;
        while (i * i < n) {
            cout << i * i << " ";
            i++;
        }
        cout << "\n\n";
    }
    
    // Calculate using different methods
    int result1 = countPerfectSquares_Method1(n);
    int result2 = countPerfectSquares_Method2(n);
    int result3 = countPerfectSquares_Method3(n);
    
    cout << "Count using Method 1 (Square Root): " << result1 << endl;
    cout << "Count using Method 2 (Binary Search): " << result2 << endl;
    cout << "Count using Method 3 (Linear Count): " << result3 << endl;
    
    cout << "\nAnswer: " << result1 << " perfect squares are less than " << n << endl;
    
    return 0;
}
