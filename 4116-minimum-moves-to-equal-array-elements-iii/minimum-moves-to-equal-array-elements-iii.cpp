class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = nums[0];

        for(auto i : nums)
        {
            if( i > maxi)
                maxi = i;
        }

        int ans = 0;

        for(auto i : nums)
        {
            ans += maxi-i;
        }

        return ans;
    }
};