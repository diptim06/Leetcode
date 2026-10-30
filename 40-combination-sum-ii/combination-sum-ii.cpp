class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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

        for(int ind = i; ind<c.size(); ind++)
        {
            if( ind > i and c[ind-1] == c[ind]) continue;

            if(c[ind] > bal) break;

            curr.push_back(c[ind]);
            solve(c, bal - c[ind], ans, curr, ind+1);
            curr.pop_back();
        }
    }
};