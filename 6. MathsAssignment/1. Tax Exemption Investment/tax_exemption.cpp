#include <iostream>
using namespace std;

int main() {
    int X, Y;
    
    cout << "Enter your annual earnings (X): ";
    cin >> X;
    
    cout << "Enter the tax exemption limit (Y): ";
    cin >> Y;
    
    // Check if earnings are strictly more than Y
    if (X <= Y) {
        cout << "\nYou don't need to pay taxes as your earnings are not more than " << Y << " rupees.\n";
        cout << "Minimum investment required: 0 rupees\n";
    } else {
        // Calculate minimum investment to bring earnings to Y
        int minInvestment = X - Y;
        cout << "\nYour earnings: " << X << " rupees\n";
        cout << "Tax exemption limit: " << Y << " rupees\n";
        cout << "Minimum investment required: " << minInvestment << " rupees\n";
        cout << "\nAfter investing " << minInvestment << " rupees, your taxable income will be " << Y << " rupees.\n";
        cout << "You won't have to pay taxes!\n";
    }
    
    return 0;
}
