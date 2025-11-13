#include <iostream>
#include <algorithm>
using namespace std;

// Method 1: Using sum and XOR
void findMissingAndRepeating_Method1(int arr[], int n) {
    long long sumN = (long long)n * (n + 1) / 2;
    long long sumN2 = (long long)n * (n + 1) * (2 * n + 1) / 6;
    
    long long sumArr = 0, sumArr2 = 0;
    
    for (int i = 0; i < n; i++) {
        sumArr += arr[i];
        sumArr2 += (long long)arr[i] * arr[i];
    }
    
    // A - B = sumN - sumArr (where A is missing, B is repeating)
    long long diff = sumN - sumArr;
    
    // A² - B² = sumN2 - sumArr2
    long long diff2 = sumN2 - sumArr2;
    
    // A + B = (A² - B²) / (A - B)
    long long sum = diff2 / diff;
    
    // Now solve: A - B = diff and A + B = sum
    int missing = (diff + sum) / 2;
    int repeating = (sum - diff) / 2;
    
    cout << "\nMissing number (A): " << missing << endl;
    cout << "Repeating number (B): " << repeating << endl;
}

// Method 2: Using sorting
void findMissingAndRepeating_Method2(int arr[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    sort(temp, temp + n);
    
    int repeating = -1, missing = -1;
    
    // Find repeating
    for (int i = 0; i < n - 1; i++) {
        if (temp[i] == temp[i + 1]) {
            repeating = temp[i];
            break;
        }
    }
    
    // Find missing
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (temp[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            missing = i;
            break;
        }
    }
    
    cout << "\nMissing number (A): " << missing << endl;
    cout << "Repeating number (B): " << repeating << endl;
}

// Method 3: Using frequency array
void findMissingAndRepeating_Method3(int arr[], int n) {
    int freq[n + 1] = {0};
    
    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    int missing = -1, repeating = -1;
    
    // Find missing and repeating
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            missing = i;
        } else if (freq[i] == 2) {
            repeating = i;
        }
    }
    
    cout << "\nMissing number (A): " << missing << endl;
    cout << "Repeating number (B): " << repeating << endl;
}

void displayArray(int arr[], int n) {
    cout << "Array: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int n;
    
    cout << "Enter the size of array (N): ";
    cin >> n;
    
    if (n < 2) {
        cout << "Array size must be at least 2!" << endl;
        return 0;
    }
    
    int arr[n];
    
    cout << "Enter " << n << " elements (one number should repeat, one should be missing from 1 to " << n << "):\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> arr[i];
    }
    
    cout << "\n========================================\n";
    displayArray(arr, n);
    cout << "Expected range: {1, 2, 3, ..., " << n << "}\n";
    cout << "========================================\n";
    
    cout << "\n--- Method 1: Using Sum and Sum of Squares ---";
    findMissingAndRepeating_Method1(arr, n);
    
    cout << "\n--- Method 2: Using Sorting ---";
    findMissingAndRepeating_Method2(arr, n);
    
    cout << "\n--- Method 3: Using Frequency Array ---";
    findMissingAndRepeating_Method3(arr, n);
    
    return 0;
}
