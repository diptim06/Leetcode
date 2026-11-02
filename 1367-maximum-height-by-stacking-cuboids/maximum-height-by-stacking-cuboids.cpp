class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        vector<vector<int>> dp(cuboids.size(), vector<int>(cuboids.size() + 1, -1));

        for (auto& c : cuboids) {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        reverse(cuboids.begin(), cuboids.end());

        return solve(cuboids, 0, -1, dp);
    }


    int solve(vector<vector<int>> &cuboids, int i, int j, vector<vector<int>> &dp)
    {
        if(i == cuboids.size())
            return 0;
        
        if(dp[i][j+1] != -1)
            return dp[i][j+1];

        int exc = solve(cuboids, i+1, j, dp);

        int inc = 0;

        if(j == -1 or (cuboids[i][0] <= cuboids[j][0] and cuboids[i][1] <= cuboids[j][1] and cuboids[i][2] <= cuboids[j][2]))
            inc = cuboids[i][2] + solve(cuboids, i+1, i, dp);


        return dp[i][j+1] = max(inc, exc);
    }
};