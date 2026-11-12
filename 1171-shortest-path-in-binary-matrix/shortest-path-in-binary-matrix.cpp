class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 or grid[n-1][n-1] == 1)
            return -1;

        if(n==1)
            return 1;

        vector<pair<int, int>> disr = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};

        queue<array<int, 3>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        q.push({0, 0, 1});

        visited[0][0] = true;

        //bfs
        while(!q.empty())
        {
            auto [r,c,dist] = q.front();
            q.pop();

            if(r== n-1 and c==n-1)
                return dist;

            for(auto [dr, dc] : disr)
            {
                int nr = r + dr, nc = c + dc;

                if(nr >= 0 and nr < n and nc >= 0 and nc <n and grid[nr][nc] == 0 && !visited[nr][nc])
                {
                    visited[nr][nc] = true;
                    q.push({nr, nc, dist+1});
                }
            }
        }
        return -1;
    }
};