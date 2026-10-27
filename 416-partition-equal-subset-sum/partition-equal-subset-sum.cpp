class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums)
            sum += i;

        if (sum % 2 != 0)
            return false;

        vector<int> prev(sum + 1, 0);
        prev[0] = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            vector<int> curr(sum + 1, 0);
            for (int diff = sum; diff >= 0; diff--) {
                bool c1 = (diff + nums[i] <= sum) ? prev[diff + nums[i]] : false;
                bool c2 = prev[abs(diff - nums[i])];

                curr[diff] = c1 || c2;
            }
            prev = std::move(curr);
        }

        return prev[0];
    }
};