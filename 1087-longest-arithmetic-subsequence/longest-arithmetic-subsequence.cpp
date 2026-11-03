class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);

        if(n <= 2)
            return n;

        int ans = 0;
        for(int i = 0; i<n-1; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                ans = max(ans , 2 + solve(i, nums[j] - nums[i], nums, dp));
            }
        }

        return ans;
    }

    int solve( int i, int diff, vector<int> &nums,vector<unordered_map<int, int>> &dp)
    {
        if( i<0)
            return 0;

        if(dp[i].count(diff))
            return dp[i][diff];
             
        int ans = 0;

        for(int j = i-1; j>=0; j--)
        {
            if(nums[i] - nums[j] == diff)
                ans = max(ans, 1 + solve(j, diff, nums, dp));
        }

        return dp[i][diff] = ans;
    }
};