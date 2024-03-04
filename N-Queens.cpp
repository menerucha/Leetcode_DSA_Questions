class Solution
{
public:
    bool queenCanBePlacedAtPos(vector<string> &board, int i, int j)
    {
        int n = board.size();
        for (int k = 0; k < n; k++)
        {
            if (board[i][k] == 'Q' || board[k][j] == 'Q')
                return false;
            if (i - k >= 0 && j - k >= 0 && board[i - k][j - k] == 'Q')
                return false;
            if (i + k < n && j + k < n && board[i + k][j + k] == 'Q')
                return false;
            if (i - k >= 0 && j + k < n && board[i - k][j + k] == 'Q')
                return false;
            if (i + k < n && j - k >= 0 && board[i + k][j - k] == 'Q')
                return false;
        }
        return true;
    }
    void placeN_minus1Queens(vector<string> &board, int i, int n, vector<vector<string>> &ans)
    {
        if (i >= board.size())
        {
            if (n == 0)
                ans.push_back(board);
            return;
        }
        for (int j = 0; j < board.size(); j++)
        {
            if (queenCanBePlacedAtPos(board, i, j))
            {
                board[i][j] = 'Q';
                placeN_minus1Queens(board, i + 1, n - 1, ans);
                board[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, "");
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                board[x].push_back('.');

        for (int j = 0; j < n; j++)
        {
            board[0][j] = 'Q';
            placeN_minus1Queens(board, 1, n - 1, ans);
            board[0][j] = '.';
        }
        return ans;
    }
};