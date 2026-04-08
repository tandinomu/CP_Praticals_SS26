#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string username;
    cin >> username;
    
    set<char> distinct;
    for (char c : username) {
        distinct.insert(c);
    }
    
    if (distinct.size() % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }
    
    return 0;
}