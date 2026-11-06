class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int cnt = 0;

        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    int curr = dfs(i, j, grid);
                    cnt = max(curr, cnt);
                }
            }
        }

        return cnt;
    }
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if(i<0 or j<0 or i>= grid.size() or j>=grid[0].size())
            return 0 ;

        if(grid[i][j] == 0)
            return 0;

        int curr = 0;

        grid[i][j] = 0;

        return 1 + dfs(i+1, j, grid) + dfs(i, j+1, grid) + dfs(i-1, j, grid) + dfs(i, j-1, grid);

        
    }
};