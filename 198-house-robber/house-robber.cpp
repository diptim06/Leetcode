class Solution {
public:
    int rob(vector<int>& nums) {
        int prevrob = 0; 
        int maxrob = 0;


        for(int i = 0; i<nums.size(); i++)
        {
            int temp = max(prevrob+nums[i], maxrob);
            prevrob = maxrob;
            maxrob = temp;
        }

        return maxrob;
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