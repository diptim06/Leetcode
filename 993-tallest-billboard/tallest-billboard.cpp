class Solution {
public:
    int tallestBillboard(vector<int>& rods) {

        int sum = 0;
        for(int i = 0; i<rods.size(); i++)
        {
            sum+= rods[i];
        }

        vector<vector<int>> dp(rods.size(), vector<int>(sum+1, -1));

        // dp[rods.size()][0] = 
        // for(int i = rods.size()-1; i>=0; i--)
        // {
        //     for(int j = sum; j>=0; j--)
        //     {
        //         dp[]
        //     }
        // }

        int ans = solve(rods, 0, 0, dp);
        return max(ans,0);
    }

    int solve(vector<int> &rods, int diff, int index, vector<vector<int>> &dp)
    {
        if(index >= rods.size())
        {
            return (diff==0) ? 0 : -1e7;
            
        }

        if(dp[index][diff]!= -1)
        {
            return dp[index][diff];
                
        }

        int res = solve(rods,diff, index+1, dp);
        res = max(res, solve(rods, diff+rods[index], index+1, dp));

        if(diff>=rods[index])
            res = max(res, rods[index]  + solve(rods, diff - rods[index], index+1, dp));
        else
            res = max(res, diff+ solve(rods, rods[index] - diff, index+1, dp));
        
        return dp[index][diff] = res;

    }
};