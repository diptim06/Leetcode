class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto x = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        auto y = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(x, y);
    }
};