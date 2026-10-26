class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size()+1, vector<int> (values.size()+1, -1));
        return solve(values, 0, values.size()-1, dp);
    }
    
    int solve(vector<int> &v, int i, int j, vector<vector<int>> &dp)
    {
        if(i+1 == j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e7; 
        for(int k = i+1; k < j; k++)
        {
            ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k, dp) + solve(v, k, j, dp) );
        }

        return dp[i][j] = ans;
    }
};