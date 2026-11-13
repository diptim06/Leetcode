class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> memo(n, vector<int>(k + 2, -1));
        for(auto f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }

        int ans = dfs(src, dst, k+1, adj, memo);

        return ans >= 1e9 ? -1 : ans;
    }

    int dfs(int curr, int dst, int k, vector<vector<pair<int, int>>> &adj, vector<vector<int>> &memo)
    {
        if(curr == dst)
            return 0;

        if(k == 0)
            return 1e9;

        if (memo[curr][k] != -1)
            return memo[curr][k];

        int ans = 1e9;

        for(auto [nextcity, price] : adj[curr])
        {
            int currprice = dfs(nextcity, dst, k-1, adj, memo);
            ans = min(ans, currprice + price);
        }

        return memo[curr][k] = ans;
    }
};