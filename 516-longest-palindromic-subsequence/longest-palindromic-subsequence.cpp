class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1, 0));

        for(int i = 0 ; i<s.length(); i++)
            dp[i][i] = 1;
        
        for(int i = s.length()-2; i>=0; i--)
        {
            for(int j = i+1; j < s.length(); j++)
            {
                if(s[i] == s[j])
                    dp[i][j] =  2+dp[i+1][j-1];

                else
                {

                    int inc = dp[i+1][j];

                    int exc = dp[i][j-1];

                    dp[i][j] = max(inc, exc);
                }
            }
        }

        return dp[0][s.length()-1];
    }

    // int solve(string &s, int i, int j, vector<vector<int>> &dp)
    // {
    //     if(i>j)
    //         return 0;
    //     if(i==j)
    //         return 1;

    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
        
    //     if(s[i] == s[j])
    //         return 2+solve(s, i+1, j-1, dp);

    //     int inc = solve(s, i + 1, j, dp);

    //     int exc = solve(s, i, j-1, dp);

    //     return dp[i][j] = max(inc, exc);
    // }
};