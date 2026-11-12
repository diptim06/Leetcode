class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        if(nums.size()==1)
            return 1;
        
        int inc = 1;
        int dec = 1;
        int maxlen = 1;

        int i = 1;


        while(i < nums.size())
        {
            if(nums[i-1] < nums[i])
                inc++;
            else
                inc = 1;

            if(nums[i-1] > nums[i])
            {
                dec++;
            }
            else
                dec = 1;

            maxlen = max({maxlen, dec, inc});
            i++;
        }

        return maxlen;

        return max(inc, dec);
    }
};