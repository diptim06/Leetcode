class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));

        dist[0][0] = 0;
        st.insert({0, {0, 0}});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (!st.empty())
        {
            auto it = *(st.begin());
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            st.erase(it);

            if (r == rows - 1 && c == cols - 1)
            {
                return d;
            }

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                {
                    int newEffort = max(d, abs(heights[r][c] - heights[nr][nc]));

                    if (newEffort < dist[nr][nc])
                    {
                        if (dist[nr][nc] != 1e9)
                        {
                            st.erase({dist[nr][nc], {nr, nc}});
                        }
                        dist[nr][nc] = newEffort;
                        st.insert({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};