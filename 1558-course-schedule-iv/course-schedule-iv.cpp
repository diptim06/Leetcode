class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries)
    {
        unordered_map<int , vector<int>> adj;

        for(vector<int> edge : pre)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool>ans;
        for(vector<int> curr : queries)
        {
            int src = curr[0];
            int dest = curr[1];
            vector<bool> visited(n,false);

            bool path = DFS(src , dest , n , adj,visited);

            ans.push_back(path);
        }

        return ans;
        
    }


    bool DFS(int src , int dest , int &n ,unordered_map<int , vector<int>> &adj , vector<bool> &visited)
    {
        visited[src] = true;
        if(src == dest)
            return true;

        for(int neighbour : adj[src])
        {
            if(!visited[neighbour])
            {
                bool path = DFS(neighbour , dest , n , adj , visited);
                if(path)
                    return true;
            }
        }

        return false;

        
    }
};