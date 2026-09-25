class Solution {
public:
    int solve(int n, vector<int> &dp)
    {
        if(n==0 or n==1)
            return n;

        //step3
        if(dp[n]!=-1)
            return dp[n];

        //step2
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
    int fib(int n) {
        //step1
        vector<int> dp(n+1, -1);
        solve(n, dp);
        
        if(n==0 or n==1)
            return n;

        return dp[n];
    }
};