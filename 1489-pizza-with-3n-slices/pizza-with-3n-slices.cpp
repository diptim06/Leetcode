class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size() / 3;
        vector<vector<int>> dp(slices.size()+1, vector<int>(k+1, -1));

        int case1 = solve(slices, 0, slices.size()-2, k, dp);

        vector<vector<int>> dp2(slices.size()+1, vector<int>(k+1, -1));
        int case2 = solve(slices, 1, slices.size()-1, k, dp2);

        return max(case1, case2);
    }

    int solve(vector<int> &slices, int i, int last, int k, vector<vector<int>> &dp)
    {
        if(k <= 0 or i > last)
            return 0;

        if(dp[i][k]!=-1)
            return dp[i][k];

        int exc = solve(slices, i+1, last, k, dp);

        int inc = slices[i] + solve(slices, i+2, last, k-1, dp);

        return dp[i][k] = max(exc, inc);
    }
};