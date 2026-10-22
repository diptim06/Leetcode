class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        
        deque<int> dq;

        for(int i = 0; i < k-1; i++)
        {
            while(!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();

            
            dq.push_back(i);
        }

        for(int i = 0; i<=nums.size()-k; i++)
        {
            int end = i+k-1;

            while(!dq.empty() and nums[dq.back()] <= nums[end])
            {
                dq.pop_back();
            }
            dq.push_back(end);

            if(!dq.empty() and dq.front() < i)
            {
                dq.pop_front();
            }

            ans.push_back(nums[dq.front()]);

        }

        return ans;
    }
};