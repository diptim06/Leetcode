
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;

        sort(nums.begin(), nums.end());

        vector<long long> pow2(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) 
        {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }

        long long ans = 0;
        
        int l = 0, r = nums.size()-1;
        
        while(l<=r)
        {
            if(nums[l]+nums[r] <= target)
            {
                ans = (ans + pow2[r - l]) % mod;
                l++;
            }
            else
                r--;
        }

        return (int)ans;
    }
};