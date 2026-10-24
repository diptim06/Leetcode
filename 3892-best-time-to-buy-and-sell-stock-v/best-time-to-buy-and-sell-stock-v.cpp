class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        if(prices.empty() or k == 0)
            return 0;
            
        vector<vector<vector<long long>>> dp(prices.size(), vector<vector<long long>>(k+1, vector<long long>(3, -1e18)));
        return solve(prices, k, 0, 0, dp);
    }

    long long solve(vector<int> &prices, int limit, int index, int state, vector<vector<vector<long long>>> &dp)
    {
        if(index == prices.size())
            return (state == 0) ? 0 : -1e15;

        if(limit == 0 and state == 0)
            return 0;

        if(dp[index][limit][state] != -1e18)
            return dp[index][limit][state];

        long long profit = 0;

        if(state == 0)
        {
            long long buy = -prices[index] + solve(prices, limit, index+1, 1, dp);
            long long sell = prices[index] + solve(prices, limit, index+1, 2, dp);
            long long skip = 0 + solve(prices, limit, index+1, 0, dp);
            profit = max({buy, sell, skip});
        }
        else if(state == 1)
        {
            long long sellnow = prices[index] + solve(prices, limit-1, index+1, 0, dp);
            long long skipnow = 0 + solve(prices, limit, index+1, 1, dp);
            profit = max({sellnow, skipnow});
        }
        else
        {
            long long buynow = -prices[index] + solve(prices, limit-1, index+1, 0, dp);
            long long skipnow = 0 + solve(prices, limit, index+1, 2, dp);
            profit = max({buynow, skipnow});
        }

        return dp[index][limit][state] = profit;
    }
};