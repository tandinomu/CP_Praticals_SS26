// Problem 5 — Balanced Line Problem

#include <iostream>
#include <deque>
#include <string>
using namespace std;

void printLine(deque<int>& dq) {
    cout << "Line: [";
    for (int i = 0; i < (int)dq.size(); i++) {
        cout << dq[i];
        if (i != (int)dq.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    deque<int> line; 

    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    cout << "\nOperations:\n";
    cout << "  push_front x  → add person x to front\n";
    cout << "  push_back x   → add person x to back\n";
    cout << "  pop_front     → remove person from front\n";
    cout << "  pop_back      → remove person from back\n\n";

    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;

        if (op == "push_front") {
            int x;
            cin >> x;
            line.push_front(x);
            cout << "push_front " << x << " → ";

        } else if (op == "push_back") {
            int x;
            cin >> x;
            line.push_back(x);
            cout << "push_back " << x << " → ";

        } else if (op == "pop_front") {
            if (!line.empty()) {
                cout << "pop_front (removed " << line.front() << ") → ";
                line.pop_front();
            } else {
                cout << "pop_front → Line is empty!\n";
                continue;
            }

        } else if (op == "pop_back") {
            if (!line.empty()) {
                cout << "pop_back (removed " << line.back() << ") → ";
                line.pop_back();
            } else {
                cout << "pop_back → Line is empty!\n";
                continue;
            }
        }

        printLine(line);
    }

    return 0;
}
