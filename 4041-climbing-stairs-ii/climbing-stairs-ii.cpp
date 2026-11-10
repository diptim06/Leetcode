class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return solve(n, costs, 0, dp);
    }

    int solve(int n, vector<int> &costs, int i, vector<int> &dp)
    {
        if(n==0)
            return 0;
        
        if(i>=costs.size())
            return 0;

        if(dp[i] != -1) return dp[i];
        int ans = 1e9;

        for(int step = 1 ; step<=3; ++step)
        {
            int next = i + step;
            if(next <= n)
            {
                int curr = costs[next-1] + (step*step) + solve(n, costs, next, dp);
                ans = min(ans, curr);
            }
        }
        return dp[i] = ans;
    }
};