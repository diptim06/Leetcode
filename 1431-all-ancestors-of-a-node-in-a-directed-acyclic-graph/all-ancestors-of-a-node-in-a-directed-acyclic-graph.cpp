class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> revAdj(n);
        for (auto& edge : edges) {
            revAdj[edge[1]].push_back(edge[0]);
        }
        
        vector<vector<int>> result(n);

        for (int i = 0; i < n; i++) 
        {
            vector<bool> visited(n, false);

            dfs(i, revAdj, visited);
            
            for (int j = 0; j < n; j++) 
            {
                if (visited[j] && j != i) {
                    result[i].push_back(j);
                }
            }
        }
        
        return result;
    }
    
    void dfs(int u, vector<vector<int>>& revAdj, vector<bool>& visited) 
    {
        visited[u] = true;
        for (int neighbor : revAdj[u]) 
        {
            if (!visited[neighbor]) 
            {
                dfs(neighbor, revAdj, visited);
            }
        }
    }
};