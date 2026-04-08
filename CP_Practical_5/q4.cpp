#include <iostream>
#include <string>
using namespace std;

int main() {
    string n;
    cin >> n;
    
    int count = 0;
    for (char c : n) {
        if (c == '4' || c == '7') {
            count++;
        }
    }
    
    string countStr = to_string(count);
    bool isLucky = true;
    for (char c : countStr) {
        if (c != '4' && c != '7') {
            isLucky = false;
            break;
        }
    }
    
    cout << (isLucky ? "YES" : "NO") << endl;
    
    return 0;
}