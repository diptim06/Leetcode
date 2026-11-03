class Solution {

    public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solve(obstacles, 2, 0, dp);
    }


    int solve(vector<int>& obstacles, int lane, int index, vector<vector<int>>& dp) {
        int n = obstacles.size();
        
        if (index == n - 1) return 0;

        if (dp[lane][index] != -1) return dp[lane][index];

        
        if (obstacles[index + 1] != lane) {
            return dp[lane][index] = solve(obstacles, lane, index + 1, dp);
        }

        
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++) {
            if (lane != i && obstacles[index] != i) {
                ans = min(ans, 1 + solve(obstacles, i, index, dp));
            }
        }

        return dp[lane][index] = ans;
    }


};