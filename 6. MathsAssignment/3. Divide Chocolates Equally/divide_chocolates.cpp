#include <iostream>
using namespace std;

int main() {
    int N;
    
    cout << "Enter the total number of chocolates (N): ";
    cin >> N;
    
    cout << "\nTotal chocolates: " << N << endl;
    
    // Check if chocolates can be divided equally between 2 people
    if (N % 2 == 0) {
        cout << "Result: YES, chocolates can be divided equally!\n";
        cout << "\nAshu will get: " << N / 2 << " chocolates\n";
        cout << "Arvind will get: " << N / 2 << " chocolates\n";
    } else {
        cout << "Result: NO, chocolates cannot be divided equally!\n";
        cout << "\nThe number " << N << " is odd, so it cannot be divided equally between 2 people.\n";
        cout << "One person will get: " << N / 2 << " chocolates\n";
        cout << "Other person will get: " << (N / 2 + 1) << " chocolates\n";
        cout << "Remaining chocolate: 1\n";
    }
    
    return 0;
}
