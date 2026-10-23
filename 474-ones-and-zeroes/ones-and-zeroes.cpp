class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return solve(strs, m, n, 0, dp);
        
    }

    int solve(vector<string> &strs, int m, int n, int i, vector<vector<vector<int>>> &dp)
    {

        if(i == strs.size())
            return 0;

        int z = 0, o = 0;
        for(char s : strs[i])
        {
            if(s == '0')
                z++;
            
            else
                o++;
        }

        if(dp[i][m][n] != -1)
            return dp[i][m][n];

        int exc = solve(strs, m, n, i+1, dp);
        int inc = 0;
        if( m-z >= 0 and n-o >=0)
            inc = solve(strs, m-z, n-o, i+1, dp)+1;
        

        return dp[i][m][n] = max(inc, exc);
    }
};