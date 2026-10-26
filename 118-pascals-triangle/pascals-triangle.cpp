class Solution {
public:
    vector<vector<int>> generate(int num) {
        
        vector<vector<int>> ans;

        for(int n = 1; n<=num; n++)
        {   
            vector<int> a(n, 0);

            for(int i = 0; i<n ; i++)
            {   
                if(i == 0 or i == n-1)
                    a[i] = 1;
                else
                    a[i] = ans[n-2][i-1] + ans[n-2][i];
            }

            ans.push_back(a);
        }

        return ans;
    }
};