class Solution
{
public:
    void dfs(int row, int col, int color, int initColor, vector<vector<int>> &ans, vector<vector<int>> &image, int delRow[], int delCol[])
    {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == initColor && ans[nRow][nCol] != color)
            {
                dfs(nRow, nCol, color, initColor, ans, image, delRow, delCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> ans = image;
        int initColor = image[sr][sc];
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, 1, -1};
        dfs(sr, sc, color, initColor, ans, image, delRow, delCol);
        return ans;
    }
};