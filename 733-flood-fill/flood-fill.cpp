class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;

        int num = image[sr][sc];

        solve(image, sr, sc, color, num);

        return image;

    }

    void solve(vector<vector<int>> &image, int i, int j, int color, int num)
    {
        if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size())
            return;

        if(image[i][j] != num)
            return;

        
        image[i][j] = color;

        solve(image, i+1, j, color, num);
        solve(image, i, j+1, color, num);
        solve(image, i-1, j, color, num);
        solve(image, i, j-1, color, num);
    }
};