class Solution {
public:
    int minOperations(string s) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());

        if(s==sorted)
            return 0;

        if(s.length()<=2)
            return -1;

        char mn = sorted[0];
        char mx = sorted[sorted.size()-1];

        if(mn == s[0] or mx == s[s.size()-1])
            return 1;

        if (s.find(mn) == s.size() - 1 &&
            s.rfind(mx) == 0) {
            return 3;
        }

        return 2;
    }
};