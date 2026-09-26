class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n+1, -1);
        dp[n] = 1;

        for(int i = n-1; i>=0; i--)
        {
            if(i == n-1)
                dp[i] = dp[i+1];
            else
                dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];
    }

    int solve( int &n, int i, vector<int> &dp)
    {

        if(i==n)
            return 1;

        if(i>n)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        
        dp[i] = solve(n, i+1, dp) + solve(n, i+2, dp);
        return dp[i];
    }
};