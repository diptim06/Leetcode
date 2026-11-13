class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        int l=0;
        vector<string> ans;
      
        for(int r=1;r<=n;r++){
            if(r==n|| (long long)nums[r]-nums[r-1]!=1){
                if(l==r-1)
                    ans.push_back(to_string(nums[l]));
                else
                    ans.push_back(to_string(nums[l])+"->"+to_string(nums[r-1]));
                
                l=r;
            }
        }
        return ans;
    }
};