class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size(), start = 0, maxLen = 0;

        for (int k = 1; k <= 26; ++k) {
            unordered_map<char, int> mp;
            int l = 0;

            for (int r = 0; r < n; ++r) {
                mp[s[r]]++;

                while (mp.size() > 2 * k) {
                    if (--mp[s[l]] == 0) mp.erase(s[l]);
                    l++;
                }

                bool nice = true;
                for (auto& [ch, a] : mp) {
                    if (!mp.count(ch ^ 32)) {
                        nice = false;
                        break;
                    }
                }

                if (nice && r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
            }
        }

        return maxLen ? s.substr(start, maxLen) : "";
    }
};