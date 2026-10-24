class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int> (3, -1)));

        return solve(prices, 0, 1, 2, dp);
    }

    int solve(vector<int> &prices, int i, bool buy, int limit, vector<vector<vector<int>>> &dp)
    {
        if(i==prices.size() or limit==0)
        {
            return 0;
        }
        if(dp[i][buy][limit] != -1)
            return dp[i][buy][limit];

        int profit = 0;

        if(buy)
            profit = max(-prices[i] + solve(prices, i+1, 0, limit, dp), 0+ solve(prices, i+1, 1, limit, dp));

        else
            profit = max(prices[i] + solve(prices, i+1, 1, limit-1, dp), 0 + solve(prices, i+1, 0, limit, dp));

        return dp[i][buy][limit] = profit;
    }   
};