class Solution {
public:
    int integerBreak(int n) {

        if(n == 3)
            return 2;
        if(n==2)
            return 1;
            
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }

    int solve(int n, vector<int> &dp)
    {
        if(n<=3)
            return n;

        if(dp[n]!= -1)
            return dp[n];

        
        int case1 = solve(n-2, dp)*2;
        int case2 = solve(n-3, dp)*3;

        dp[n] = max(case1, case2);

        return dp[n];
        
    }
};