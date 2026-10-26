class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, 0));
        sort(s.begin(), s.end());

        for(int i = s.size()-1; i>=0; i--)
        {
            for(int time = s.size()-1; time>=0; time--)
            {
                int inc = s[i] * (time+1) + dp[i+1][time+1];
                int exc = 0 + dp[i+1][time];

                dp[i][time] = max(inc, exc);
            }
        }

        return dp[0][0];
    }

    // int solve(vector<int> &s, int i, int time, vector<vector<int>> &dp)
    // {
    //     if(i == s.size())
    //         return 0;
    //     if(dp[i][time] != -1)
    //         return dp[i][time];

    //     int inc = s[i] * (time+1) + solve(s, i+1, time+1, dp);
    //     int exc = 0 + solve(s, i+1, time, dp);

    //     return dp[i][time] = max(inc, exc);
    // }
};