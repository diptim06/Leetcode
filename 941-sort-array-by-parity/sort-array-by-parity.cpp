class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int j = nums.size()-1, i = 0;

        while(i<j)
        {
            if(nums[j] %2 == 0 and nums[i] %2 != 0)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }


            else if(nums[j] %2 == 0 and nums[i] %2 == 0)
                i++;
            else
                j--;
        }

        return nums;
    }
};