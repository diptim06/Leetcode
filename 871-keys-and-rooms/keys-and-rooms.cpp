class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n, false);

        dfs(0, rooms, visited);

        for( bool v : visited)
        {
            if(!v) return false;
        }
        return true;
    }

    void dfs(int curr, vector<vector<int>>& rooms, vector<bool> &visited)
    {
        visited[curr] = true;
        for(int next : rooms[curr])
        {
            if(!visited[next])
                dfs(next, rooms, visited);
        }
    }
};