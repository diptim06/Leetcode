class Solution {
public:
    int numDecodings(string s)
    {
        if(s == "0")
            return 0;

        if(s.length() > 2 and s[s.length()-1] == '0'  and s[s.length()-2] == '0')
            return 0;

        vector<int> dp(s.length()+1,-1);

        return solve(s,dp);
    }

    int solve(string s,vector<int> &dp)
    {
        if(s == "")
            return 1;

        if(dp[s.length()] != -1)
            return dp[s.length()];

        int a = 0;
        if(s.length() >= 1 and s[0] != '0') {
            a = solve(s.substr(1) , dp);
        }

        int b = 0;
        if(s.length() >= 2 and s[0] != '0' and stoi(s.substr(0, 2)) <= 26) {
            b = solve(s.substr(2) , dp);
        }

        dp[s.length()] = a + b;
        return dp[s.length()];
    }
};