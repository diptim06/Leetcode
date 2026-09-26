class Solution {
public:
    int coinChange(vector<int>& coins, int a) {

        vector<int> dp(a+1, -1);

        int ans = solve(coins, a, dp); 

        return ans == INT_MAX ? -1 : ans;
    }

    int solve(vector<int> coins, int bal, vector<int> &dp)
    {
        if(bal==0) 
            return 0; 
        
        if(bal < 0)
            return INT_MAX;


        if(dp[bal]!=-1)
            return dp[bal];
        
        int mini = INT_MAX;

        for(int i: coins)
        {   
            int res = solve(coins, bal-i, dp);

            if(res!= INT_MAX)
                res += 1;
            mini = min(mini, res); 
        }

        dp[bal] = mini;
        return dp[bal];
    }
};