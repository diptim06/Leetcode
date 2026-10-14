class Solution {
public:
    int rob(vector<int>& nums) {

        vector<int> dp(nums.size()+2, 0);


        for(int i = nums.size()-1; i>=0; i--)
        {
            int case1 = dp[i+2] + nums[i];

            int case2 = dp[i+1];
            

            dp[i] = max(case1, case2);
        }

        return dp[0];
    }

    int solve( vector<int>& nums, int i, vector<int> &dp){
        if(i>nums.size()-1 )
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];

        int case1 = solve(nums, i+2, dp)+nums[i];
        int case2 = solve(nums, i+1, dp) + 0;

        dp[i] = max(case1, case2);
        return dp[i];
    }
};