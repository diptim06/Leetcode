class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> adj;

        for (auto& pre : p) {
            adj[pre[1]].push_back(pre[0]); 
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfs;

        for(int i = 0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                bool cycle = solve(i, adj, visited, dfs);
                if(cycle)
                    return false;
            }
        }

        return true;
    }

    bool solve(int i, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfs)
    {
        visited[i] = true;
        dfs[i] = true;

        for(int neighbour : adj[i])
        {
            if(!visited[neighbour])
            {
                bool cycle = solve(neighbour, adj, visited, dfs);
                if(cycle)
                    return true;
            }
            else if(dfs[neighbour])
                return true;
        }

        dfs[i] = false;
        return false;
    }
};