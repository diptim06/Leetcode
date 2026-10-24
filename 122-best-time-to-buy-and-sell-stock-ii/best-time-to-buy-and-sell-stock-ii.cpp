class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(2, 0);

        for(int i = prices.size()-1; i>= 0; i--)
        {
            for(int j = 0; j<=1; j++)
            {
                int profit = 0;
                if(j)
                    profit = max((-(prices[i]) + dp[j-1]) , (0 + dp[j]));
                else
                    profit = max((prices[i] + dp[j+1]), (0+dp[j]));

                dp[j] = profit;
            }
        }

        return dp[1];
    }

    // int solve(vector<int> &prices, int index, bool buy, vector<vector<int>> &dp)
    // {
    //     if(index == prices.size())
    //     {
    //         return 0;
    //     }

    //     if(dp[index][buy] != -1)
    //         return dp[index][buy];

        
    //     int profit = 0;

    //     if(buy)
    //         profit = max((-(prices[index]) + solve(prices, index+1, false, dp )) , (0 + solve(prices, index+1, true, dp)));
    //     else
    //         profit = max((prices[index] + solve(prices, index+1, true, dp)), (0+solve(prices, index+1, false, dp)));

    //     return dp[index][buy] = profit;
    // }
};