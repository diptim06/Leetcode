class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int end) {

        unordered_map<int, vector<pair<int, double>>> adj(n);

        for(int i = 0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        vector<double> dist(n, 0.0);
        dist[src] = 1.0;

        set<pair<double, int>> st;
        st.insert({1.0, src});

        while(!st.empty())
        {
            auto [dis, node] = *st.rbegin();
            st.erase(prev(st.end()));

            if (node == end) return dis;

            for(auto [nextnode, nextdis] : adj[node])
            {
                if(dis * nextdis > dist[nextnode])
                {
                    st.insert({(dis*nextdis), nextnode});
                    dist[nextnode] = dis * nextdis;
                }
            }
        }

        return dist[end];
    }
};