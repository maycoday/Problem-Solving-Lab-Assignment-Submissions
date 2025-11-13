#include <iostream>
#include <cmath>
using namespace std;

// Function to find quotient using bit manipulation
int divide(int dividend, int divisor) {
    // Handle special cases
    if (divisor == 0) {
        cout << "Error: Division by zero!" << endl;
        return -1;
    }
    
    // Determine the sign of result
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    
    // Work with absolute values
    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);
    
    // Initialize quotient
    long long quotient = 0;
    
    // Find the highest power of 2 that can be subtracted
    while (a >= b) {
        long long temp = b;
        long long multiple = 1;
        
        // Double the divisor until it's greater than dividend
        while (a >= (temp << 1)) {
            temp <<= 1;      // temp = temp * 2
            multiple <<= 1;  // multiple = multiple * 2
        }
        
        // Subtract the largest shifted divisor from dividend
        a -= temp;
        quotient += multiple;
    }
    
    return sign * quotient;
}

int main() {
    int a, b;
    
    cout << "Enter dividend (a): ";
    cin >> a;
    
    cout << "Enter divisor (b): ";
    cin >> b;
    
    if (b == 0) {
        cout << "\nError: Cannot divide by zero!" << endl;
        return 0;
    }
    
    int quotient = divide(a, b);
    
    cout << "\n--- Division using Bit Manipulation ---\n";
    cout << "Dividend (a): " << a << endl;
    cout << "Divisor (b): " << b << endl;
    cout << "Quotient (a / b): " << quotient << endl;
    
    // Verification
    cout << "\nVerification: " << quotient << " × " << b << " = " << (quotient * b) << endl;
    cout << "Remainder: " << (a - (quotient * b)) << endl;
    
    return 0;
}
