class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        
        unordered_map<int, vector<int>> adj;
        for (auto& pre : p) {
            adj[pre[1]].push_back(pre[0]);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfs;
        stack<int> st;

        for(int i = 0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                if(solve(i, adj, visited, st, dfs))
                    return {};
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    bool solve(int i, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, bool> &dfs)
    {
        visited[i] = true;
        dfs[i] = true;

        for(int neighbour : adj[i])
        {
            if (!visited[neighbour])
            {
                if (solve(neighbour, adj, visited, st, dfs)) {
                    return true;
                }
            }
                
            
            else if (dfs[neighbour]) 
            {
                return true;
            }
        }
        

        dfs[i] = false;
        st.push(i);
        return false;
    }
};