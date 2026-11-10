class Solution {
public:
    int longestCycle(vector<int>& edges) {

        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfs;
        vector<int> dist(edges.size(), 0);

        int ans = -1;
        for(int i = 0; i<edges.size(); i++)
        {
            if(!visited[i])
            {
                int curr = dfssolve(i, edges, visited, dfs, dist, 1);
                ans = max(curr, ans);
            }
        }

        return ans;
    }

    int dfssolve(int i, vector<int> &edges, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfs, vector<int> &dist, int d)
    {
        visited[i] = true;
        dfs[i] = true;
        dist[i] = d;
        int len = -1;

        int neighbour = edges[i];

        if (neighbour != -1) 
        {
            if (!visited[neighbour]) 
            {
                len = max(len, dfssolve(neighbour, edges, visited, dfs, dist, d + 1));
            } 
            else if (dfs[neighbour]) 
            {
                int cyclelen = dist[i] - dist[neighbour] + 1;
                len = max(len, cyclelen);
            }
        }

        dfs[i] = false;
        return len;
    }
};