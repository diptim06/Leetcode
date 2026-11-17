class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            int v1 = edge[0], v2 = edge[1];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        

        queue<int> q;
        q.push(1);
        int cur_time = 0;
        int res = -1;
        unordered_map<int, vector<int>> visit_times;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                if (node == n) {
                    if (res != -1) {
                        return cur_time;
                    }
                    res = cur_time;
                }

                for (int nei : adj[node]) {
                    auto& nei_times = visit_times[nei];
                    if (nei_times.empty() || (nei_times.size() == 1 && nei_times[0] != cur_time)) {
                        q.push(nei);
                        nei_times.push_back(cur_time);
                    }
                }
            }

            if ((cur_time / change) % 2 == 1) {
                cur_time += change - (cur_time % change);
            }
            cur_time += time;
        }

        return -1;
    }
};