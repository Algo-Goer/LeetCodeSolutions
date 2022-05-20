/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows[9][9];
        int columns[9][9];
        int boxes[3][3][9];

        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(boxes, 0, sizeof(boxes));
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    rows[i][num]++;
                    columns[j][num]++;
                    boxes[i / 3][j / 3][num]++;
                    if (rows[i][num] > 1 || columns[j][num] > 1 || boxes[i / 3][j / 3][num] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// @lc code=end
