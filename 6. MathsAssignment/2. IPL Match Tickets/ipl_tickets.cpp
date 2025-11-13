#include <iostream>
using namespace std;

int main() {
    int N, M;
    
    cout << "Enter total number of students (N): ";
    cin >> N;
    
    cout << "Enter number of available tickets (M): ";
    cin >> M;
    
    // Calculate students who won't get tickets
    int studentsWithoutTickets;
    
    if (N <= M) {
        studentsWithoutTickets = 0;
        cout << "\nAll students can book tickets!\n";
        cout << "Students who will get tickets: " << N << endl;
        cout << "Students who won't get tickets: " << studentsWithoutTickets << endl;
        cout << "Extra tickets available: " << (M - N) << endl;
    } else {
        studentsWithoutTickets = N - M;
        cout << "\nNot enough tickets for all students!\n";
        cout << "Total students: " << N << endl;
        cout << "Available tickets: " << M << endl;
        cout << "Students who will get tickets: " << M << endl;
        cout << "Students who won't get tickets: " << studentsWithoutTickets << endl;
    }
    
    return 0;
}
