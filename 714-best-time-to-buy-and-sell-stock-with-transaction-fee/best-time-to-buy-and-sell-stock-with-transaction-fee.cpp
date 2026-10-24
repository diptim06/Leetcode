class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(2, 0);
        
        for(int i = prices.size() -1; i>=0; i--)
        {
            for(int j = 0; j<=1; j++)
            {
                int profit = 0;

                if(j)
                    profit = max((-(prices[i]) + dp[j-1]) , (0 + dp[j]));
                else
                    profit = max((prices[i] - fee + dp[j+1]), (0 + dp[j]));

                dp[j] = profit;
            }
        }

        return dp[1];
    }

    
};