class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        
        
        for(int i = 0; i<nums.size(); i++)
        {
            int sum = 0;

            for(int j = i; j<nums.size(); j++)
            {
                int len = j-i+1;
                sum += nums[j];

                if(len >= l and len <= r)
                {
                    if(sum > 0)
                        ans = min(sum, ans);
                }

                if (len > r) {
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};