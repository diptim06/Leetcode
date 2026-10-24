class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int> (3, 0));

        for(int i = prices.size()-1; i>=0; i--)
        {
            for(int j = 0; j<=1; j++)
            {
                for(int k = 1; k<=2; k++)
                {
                    int profit = 0;

                    if(j)
                        profit = max(-prices[i] + dp[j-1][k] , 0+ dp[j][k]);

                    else
                        profit = max(prices[i] + dp[j+1][k-1] , 0 + dp[j][k]);

                    dp[j][k] = profit;
                }
            }
        }

        return dp[1][2];
    }

};