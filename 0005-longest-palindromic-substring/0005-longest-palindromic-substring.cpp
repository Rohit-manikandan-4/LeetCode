#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;

                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }

                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            // Odd length palindrome (example: aba)
            expand(i, i);

            // Even length palindrome (example: bb)
            expand(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};