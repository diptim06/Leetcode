class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, ans, curr, 0);
        return ans;
    }

    void solve( vector<int> &c, int bal, vector<vector<int>> &ans, vector<int> &curr, int i)
    {
        if(bal == 0)
        {
            ans.push_back(curr);
            return;
        }

        if(bal < 0 or i == c.size())
        {
            return;
        }

        curr.push_back(c[i]);
        solve(c, bal-c[i], ans, curr, i);

        curr.pop_back();
        solve(c, bal, ans, curr, i+1);
    }
};