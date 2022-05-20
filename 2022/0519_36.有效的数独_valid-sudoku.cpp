/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
// recommend
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        if (board.size() != 9 || board.size() != board[0].size())
            return false;

        bool row[9][10]; // row[行数][数字0~9]
        bool col[9][10]; 
        bool box[9][10]; // 3*3九宫格，0~2第0行，3~5第1行，6~8第2行

        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(box, false, sizeof(box));

        int number;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                number = board[i][j] - '0'; // 将字符转换为数字
                if (row[i][number]) return false;
                if (col[j][number]) return false;
                if (box[i / 3 * 3 + j / 3][number]) return false;

                row[i][number] = true;
                col[j][number] = true;
                box[i / 3 * 3 + j / 3][number] = true;
            }
        }
        return true;
    }
};
// @lc code=end
