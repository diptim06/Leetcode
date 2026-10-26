class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        vector<vector<int>> dp(v.size(), vector<int> (v.size(), 0));

        for(int i = v.size()-1; i >= 0; i--)
        {
            for(int j = i+1; j<v.size(); j++)
            {
                for(int k = i+1; k < j; k++)
                {
                    dp[i][j]  = min(dp[i][j] == 0 ? INT_MAX : dp[i][j], v[i] * v[k] * v[j] + dp[i][k] + dp[k][j] );
                }
            }
        }

        return dp[0][v.size()-1];
    }
    
    // int solve(vector<int> &v, int i, int j, vector<vector<int>> &dp)
    // {
    //     if(i+1 == j)
    //         return 0;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     int ans = 1e7; 
    //     for(int k = i+1; k < j; k++)
    //     {
    //         ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k, dp) + solve(v, k, j, dp) );
    //     }

    //     return dp[i][j] = ans;
    // }
};