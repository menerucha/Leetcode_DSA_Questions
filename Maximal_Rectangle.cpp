class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int rows{(int)matrix.size()}, cols{(int)matrix[0].size()}, maxRectangle{};
        vector<vector<int>> mat(rows, vector<int>(cols, 0));
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                mat[r][c] = matrix[r][c] - '0';
        for (int r = 1; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                mat[r][c] = mat[r][c] * (mat[r][c] + mat[r - 1][c]);
        for (int r = 0; r < rows; ++r)
            maxRectangle = max(maxRectangle, largestRectangleArea(mat[r]));

        return maxRectangle;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(-1);
        stack<pair<int, int>> st;
        int largestArea{};
        for (int i = 0; i < (int)heights.size(); i++)
        {
            int startIdx{i};
            while (!st.empty() && heights[i] < st.top().first)
            {
                auto [height, idx] = st.top();
                st.pop();
                largestArea = max(largestArea, height * (i - idx));
                startIdx = idx;
            }
            st.push({heights[i], startIdx});
        }
        return largestArea;
    }
};