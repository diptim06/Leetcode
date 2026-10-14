class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int> dp(nums.size()+1, -1);
        int ans = solve(nums, 0, dp);
        return ans;
    }

    int solve( vector<int>& nums, int i, vector<int> &dp){
        if(i>nums.size()-1 or nums.size()==0)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];

        int case1 = solve(nums, i+2, dp)+nums[i];
        int case2 = solve(nums, i+1, dp) + 0;

        dp[i] = max(case1, case2);
        return dp[i];
    }
};