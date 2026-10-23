class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0);
    }

    int solve(vector<int> &nums, int target, int i)
    {
        if(i == nums.size() and target==0)
            return 1;

        if(i>=nums.size())
            return 0;

        int case1 = solve(nums, target - nums[i], i+1);
        int case2 = solve(nums, target + nums[i], i+1);

        int ans = case1 + case2;

        return ans;
    }
};