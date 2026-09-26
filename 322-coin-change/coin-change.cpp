class Solution {
public:
    int coinChange(vector<int>& coins, int a) {

        vector<int> dp(a+1, INT_MAX);

        dp[0] = 0;

        for(int bal = 0; bal<=a; bal++)
        {

            for(int coin : coins)
            {   
                if(bal-coin >= 0 and dp[bal-coin] != INT_MAX)
                    dp[bal] = min(dp[bal], 1+dp[bal-coin]);
                
            }
        }

        return dp[a] == INT_MAX ? -1: dp[a];
    }
};