#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    
    int x = sqrt(S1 * S3 / S2);
    int y = sqrt(S1 * S2 / S3);
    int z = sqrt(S2 * S3 / S1);
    
    int sumEdges = 4 * (x + y + z);
    
    cout << sumEdges << endl;
    
    return 0;
}