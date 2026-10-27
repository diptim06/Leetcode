class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(auto i : nums)
            sum+=i;
        
        vector<vector<int>> dp(nums.size()+2,(vector<int>(sum+1, 0)));

       
            dp[nums.size()][0] = 1;
    
        for(int i = nums.size()-1; i>=0; i--)
        {
            for(int diff= sum; diff>=0; diff--)
            {
                bool c1 = (diff + nums[i] <= sum) ? dp[i+1][diff+nums[i]] : false;
        
                bool c2 = dp[i+1][abs(diff-nums[i])];

                dp[i][diff] = c1 or c2;
            }
        }
        
        return dp[0][0];
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