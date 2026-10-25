class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> curr(n, 0);
        vector<int> next(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            curr[i] = 1; // Base case: single character palindromes (s[i...i])

            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    curr[j] = 2 + next[j - 1];
                } else {
                    int inc = next[j];      // from row i + 1
                    int exc = curr[j - 1];  // from current row i
                    curr[j] = max(inc, exc);
                }
            }

            // Row i becomes row i + 1 for the next iteration
            next = curr;
        }

        return next[n - 1];
    }
};