class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, true, dp);
    }

    int solve(vector<int> &prices, int index, bool buy, vector<vector<int>> &dp)
    {
        if(index >= prices.size())
        {
            return 0;
        }

        if(dp[index][buy] != -1)
            return dp[index][buy];

        
        int profit = 0;

        if(buy)
            profit = max((-(prices[index]) + solve(prices, index+1, false, dp )) , (0 + solve(prices, index+1, true, dp)));
        else
            profit = max((prices[index] + solve(prices, index+2, true, dp)), (0+solve(prices, index+1, false, dp)));

        return dp[index][buy] = profit;
    }
};