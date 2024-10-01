#include <iostream>
#include <stack>
using namespace std;

int steps = 0;

void moveDisk(stack<int>& source, stack<int>& destination, char s, char d) {
    int topDisk = source.top();
    source.pop();
    destination.push(topDisk);
    cout << "Move disk " << topDisk << " from " << s << " to " << d << endl;
    steps++;
}

void moveDisksBetweenTwoPoles(stack<int>& src, stack<int>& dest, char s, char d) {
    if (src.empty()) {
        int topDisk = dest.top();
        dest.pop();
        src.push(topDisk);
        cout << "Move disk " << topDisk << " from " << d << " to " << s << endl;
        steps++;
    } else if (dest.empty()) {
        int topDisk = src.top();
        src.pop();
        dest.push(topDisk);
        cout << "Move disk " << topDisk << " from " << s << " to " << d << endl;
        steps++;
    } else if (src.top() > dest.top()) {
        int topDisk = dest.top();
        dest.pop();
        src.push(topDisk);
        cout << "Move disk " << topDisk << " from " << d << " to " << s << endl;
        steps++;
    } else {
        int topDisk = src.top();
        src.pop();
        dest.push(topDisk);
        cout << "Move disk " << topDisk << " from " << s << " to " << d << endl;
        steps++;
    }
}

void towerOfHanoi(int n) {
    stack<int> rodA, rodB, rodC;

    for (int i = n; i >= 1; i--) {
        rodA.push(i);
    }

    char s = 'A', d = 'C', a = 'B';
    if (n % 2 == 0) {
        swap(d, a);  // If the number of disks is even, swap the destination and auxiliary
    }

    int totalMoves = (1 << n) - 1;  // 2^n - 1 moves

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            moveDisksBetweenTwoPoles(rodA, rodC, s, d);
        } else if (i % 3 == 2) {
            moveDisksBetweenTwoPoles(rodA, rodB, s, a);
        } else if (i % 3 == 0) {
            moveDisksBetweenTwoPoles(rodB, rodC, a, d);
        }
    }

    cout << "Total number of steps: " << steps << endl; // Print the total number of steps
}

int main() {
    int n;
    cout << "Enter the number of discs: ";
    cin >> n;  // Number of disks
    towerOfHanoi(n);
    return 0;
}
