for (int i = 0; i < n; i++)
{
    class Solution
    {
    public:
        bool isSafe(int row, int col, vector<vector<char>> &board, int value)
        {
            int n = board.size();

            for (int i = 0; i < n; i++)
            {
                if (board[row][i] == value)
                    return false;
                if (board[i][col] == value)
                    return false;
                if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == value)
                    return false;
            }
            return true;
        }
        bool solve(vector<vector<char>> &board)
        {
            int n = board.size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == '.')
                    {
                        for (char value = '1'; value <= '9'; value++)
                        {
                            if (isSafe(i, j, board, value))
                            {
                                board[i][j] = value;
                                bool aageKaSolution = solve(board);
                                if (aageKaSolution == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    board[i][j] = '.';
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }
        void solveSudoku(vector<vector<char>> &board)
        {
            solve(board);
        }
    };