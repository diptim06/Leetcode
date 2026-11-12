class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(); 
        int cols = maze[0].size(); 

        queue<pair<pair<int, int>, int>>q; 
        vector<vector<bool>>visited(rows, vector<bool>(cols, false)); 

        q.push({{entrance[0], entrance[1]}, 0}); 
        visited[entrance[0]][entrance[1]] = true; 

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1}; 

        while(!q.empty())
        {
            auto curr = q.front(); 
            q.pop(); 

            int r = curr.first.first; 
            int c = curr.first.second; 
            int steps = curr.second; 

            if((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && 
                !(r == entrance[0] && c == entrance[1]))
            {
                return steps; 
            }

            for(int i = 0; i < 4; i ++)
            {
                int nr = r + dx[i]; 
                int nc = c + dy[i]; 

                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols && 
                   maze[nr][nc] == '.' &&
                   !visited[nr][nc]){

                    visited[nr][nc] = true; 
                    q.push({{nr, nc}, steps + 1}); 
                   }
            }
        }

        return -1; 
    }
};