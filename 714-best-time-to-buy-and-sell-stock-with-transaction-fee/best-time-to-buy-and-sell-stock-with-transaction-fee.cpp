class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        
        for(int i = prices.size() -1; i>=0; i--)
        {
            for(int j = 0; j<=1; j++)
            {
                int profit = 0;

                if(j)
                    profit = max((-(prices[i]) + dp[i+1][j-1]) , (0 + dp[i+1][j]));
                else
                    profit = max((prices[i] - fee + dp[i+1][j+1]), (0 + dp[i+1][j]));

                dp[i][j] = profit;
            }
        }

        return dp[0][1];
    }

    
};