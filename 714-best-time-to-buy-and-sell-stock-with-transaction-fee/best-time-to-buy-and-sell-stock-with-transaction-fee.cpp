class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, true, dp, fee);
    }

    int solve(vector<int> &prices, int index, bool buy, vector<vector<int>> &dp, int fee)
    {
        if(index == prices.size())
        {
            return 0;
        }

        if(dp[index][buy] != -1)
            return dp[index][buy];

        
        int profit = 0;

        if(buy)
            profit = max((-(prices[index]) + solve(prices, index+1, false, dp , fee)) , (0 + solve(prices, index+1, true, dp, fee)));
        else
            profit = max((prices[index] - fee + solve(prices, index+1, true, dp, fee)), (0+solve(prices, index+1, false, dp, fee)));

        return dp[index][buy] = profit;
    }
};