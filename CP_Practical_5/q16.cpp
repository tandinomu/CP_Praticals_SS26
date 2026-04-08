#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int i = 0;
    bool magic = true;
    
    while (i < s.length()) {
        if (s.substr(i, 3) == "144") {
            i += 3;
        }
        else if (s.substr(i, 2) == "14") {
            i += 2;
        }
        else if (s[i] == '1') {
            i += 1;
        }
        else {
            magic = false;
            break;
        }
    }
    
    cout << (magic ? "YES" : "NO") << endl;
    
    return 0;
}