class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adjlist(graph.size());

        vector<vector<int>> ans;
        vector<int> temp;

        dfs(graph, 0, ans, temp);
        return ans;
    }

    void dfs(vector<vector<int>> &graph, int curr, vector<vector<int>> &ans, vector<int> &temp)
    {
        temp.push_back(curr);

        if(curr == graph.size()-1) ans.push_back(temp);

        else
        {
            for(int i = 0; i<graph[curr].size(); i++)
            {
                dfs(graph, graph[curr][i], ans, temp);
            }
        }
        temp.pop_back();

    }
};