class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int sum = 0;
        
        while(k>0)
        {
            sum+= nums[nums.size()-1];
            nums[nums.size()-1]++;
            k--;
        }
        return sum;
    }
};