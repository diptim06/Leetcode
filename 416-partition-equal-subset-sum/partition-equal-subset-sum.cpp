class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(auto i : nums)
            sum+=i;
        
        vector<vector<int>> dp(nums.size()+1,(vector<int>(sum+1, -1)));

        
        return solve(nums, 0, 0, dp);
    }

    bool solve(vector<int> &nums, int i, int diff, vector<vector<int>> &dp)
    {
        if(i == nums.size())
        {
            return diff == 0;
        }
        if(dp[i][diff] != -1)
            return dp[i][diff];

        bool c1 = solve(nums, i+1, diff + nums[i], dp);
        
        bool c2 = solve(nums, i+1, abs(diff-nums[i]), dp);

        return dp[i][diff] = c1 or c2;
    }
};