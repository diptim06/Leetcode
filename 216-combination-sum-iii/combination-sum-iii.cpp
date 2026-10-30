class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(k, n, ans, curr, 1);
        return ans;
    }

    void solve(int k, int n, vector<vector<int>> &ans, vector<int> &curr, int ind)
    {
        if(n == 0 and k == 0)
        {
            ans.push_back(curr);
            return;
        }

        for(int i = ind; i<10; i++)
        {
            curr.push_back(i);
            solve(k-1, n-i, ans, curr, i+1);
            curr.pop_back();
        }
    }
};