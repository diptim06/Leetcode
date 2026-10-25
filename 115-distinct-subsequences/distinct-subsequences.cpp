class Solution {
public:
    int numDistinct(string s, string t) {

        if(t.size() > s.size())
            return 0;
        vector<vector<unsigned long long>> dp(s.size()+1, vector<unsigned long long> (t.size()+1, 0));

        for(int i = 0; i<=s.size(); i++)
            dp[i][t.size()] = 1;

        
        for(int i = s.size()-1; i >= 0; i--)
        {
            for(int j = t.size()-1; j>=0; j--)
            {
                unsigned long long inc = 0;

                if(s[i] == t[j])
                    inc =  dp[i+1][j+1];

                unsigned long long exc = dp[i+1][j];

                dp[i][j] = inc + exc;
            }
        }

        return dp[0][0];
    }

    // int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    // {
    //     if(j == t.length())
    //         return 1;

    //     if(i == s.length())
    //         return 0;
        
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
        
    //     int inc = 0;
    //     if(s[i] == t[j])
    //         inc =  solve(s, t, i+1, j+1, dp);

    //     int exc = solve(s, t, i+1, j, dp);

    //     return dp[i][j] = inc + exc;
    // }
};