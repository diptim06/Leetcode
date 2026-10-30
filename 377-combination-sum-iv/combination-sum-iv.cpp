class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, target, dp);
    }

    int solve( vector<int> &c, int bal, vector<int> &dp)
    {
        if(bal == 0)
        {
            return 1;
        }

        if(bal < 0)
        {
            return 0;
        }

        if (dp[bal] != -1) return dp[bal];

        int ans = 0;
        for(int i = 0; i<c.size(); i++)
        {
            ans += solve(c, bal - c[i], dp);
        }

        return dp[bal] = ans;
    }
};