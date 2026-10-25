class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -2));
        return solve(nums, 0, -1, dp);
    }

    int solve(vector<int> &nums, int i, int f, vector<vector<int>> &dp)
    {
        if(i==nums.size())
            return 0;

        if(dp[i][f+1] != -2)
            return dp[i][f+1];

        int exc = solve(nums, i+1, f, dp);

        int inc = 0;
        if( f == -1 or nums[i] > nums[f])
            inc = 1 + solve(nums, i+1, i, dp);

        return dp[i][f+1] = max(inc, exc);
    }
};