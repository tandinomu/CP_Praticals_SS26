#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "==============================\n";
    cout << "  MANACHER'S ALGORITHM\n";
    cout << "==============================\n";

    string inputs[] = {"racecar", "banana", "aabbaa", "abcd", "abacaba"};
    int count = 5;

    for (int w = 0; w < count; w++) {
        string s = inputs[w];
        cout << "\nInput: \"" << s << "\"\n";

        // --- Step 1: Build transformed string ---
        // Insert '#' between every character and at both ends
        string t = "#";
        for (int i = 0; i < (int)s.size(); i++) {
            t += s[i];
            t += '#';
        }
        int n = t.size();
        cout << "  Transformed: \"" << t << "\"\n";

        // --- Step 2: Compute P[] using Manacher's logic ---
        // P[i] = how far the palindrome at position i extends
        int P[300] = {};   // radius array, all zeros
        int C = 0;         // center of rightmost palindrome so far
        int R = 0;         // right boundary of that palindrome

        for (int i = 0; i < n; i++) {
            int mirror = 2*C - i;  // mirror of i across C

            // Use previously computed value if inside right boundary
            if (i < R)
                P[i] = min(R - i, P[mirror]);

            // Expand around i as far as possible
            while (i + P[i] + 1 < n &&
                   i - P[i] - 1 >= 0 &&
                   t[i + P[i] + 1] == t[i - P[i] - 1])
                P[i]++;

            // Update C and R if this palindrome goes further right
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // --- Step 3: Show the P array ---
        cout << "  P[]:  ";
        for (int i = 0; i < n; i++) cout << P[i] << " ";
        cout << "\n";

        // --- Step 4: Find the longest palindrome ---
        int maxLen = 0, center = 0;
        for (int i = 0; i < n; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                center = i;
            }
        }
        int start = (center - maxLen) / 2;  // map back to original index
        string longest = s.substr(start, maxLen);
        cout << "  Longest palindrome: \"" << longest
             << "\" (length=" << maxLen << ")\n";

        // --- Step 5: List ALL palindromic substrings of length >= 2 ---
        cout << "  All palindromes (length >= 2):\n";
        bool found = false;
        for (int i = 0; i < (int)s.size(); i++) {
            for (int len = 2; i + len <= (int)s.size(); len++) {
                // Check if s[i..i+len-1] is a palindrome
                string sub = s.substr(i, len);
                bool ok = true;
                int l = 0, r = len - 1;
                while (l < r) {
                    if (sub[l] != sub[r]) { ok = false; break; }
                    l++; r--;
                }
                if (ok) {
                    cout << "    \"" << sub
                         << "\" at index " << i
                         << ", length " << len << "\n";
                    found = true;
                }
            }
        }
        if (!found) cout << "    (none)\n";
    }

    cout << "\n==============================\n";
    return 0;
}