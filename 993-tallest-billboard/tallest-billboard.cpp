class Solution {
public:
    int tallestBillboard(vector<int>& rods) {

        int sum = 0;
        for(int i = 0; i<rods.size(); i++)
        {
            sum+= rods[i];
        }

        vector<vector<int>> dp(rods.size()+1, vector<int>(sum+1, -1));
        int ans = solve(rods, 0, 0, 0, dp);
        return ans > 0 ? ans : 0;
    }

    int solve(vector<int> &rods, int I, int II, int index, vector<vector<int>> &dp)
    {
        if(index >= rods.size())
        {
            if(I == II)
            {
                return I;
            }
            return -1e7;
        }
        int diff = abs(I-II);

        if(dp[index][diff]!= -1)
        {
            if(dp[index][diff] == -1e7)
                return -1e7;
            else
                return dp[index][diff] + min(I,II);
                
        }

        
        int case1 = solve(rods, I+ rods[index], II, index+1, dp);
        int case2 = solve(rods, I, II + rods[index], index+1, dp);
        int case3 = solve(rods, I, II, index+1, dp);

        int best = max({case1 , case2, case3});

        if(best >= 0)
            dp[index][diff] = best - min(I,II);

        else
            dp[index][diff] = -1e7;

        return best;

    }
};