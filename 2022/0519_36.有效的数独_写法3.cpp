/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
// 写法一 Hashmap
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_map<char, int>> rows(9);
        vector<unordered_map<char, int>> cols(9);
        vector<unordered_map<char, int>> boxes(9);

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    int num =  board[i][j];
                    int box_index = (i / 3) * 3 + j / 3;
                    rows[i][num] = rows[i].count(num) != 0 ? rows[i][num] + 1 : 1;
                    cols[j][num] = cols[j].count(num) != 0 ? cols[j][num] + 1 : 1;
                    boxes[box_index][num] = boxes[box_index].count(num) != 0 ? boxes[box_index][num] + 1 : 1;

                    if (rows[i][num] > 1 || cols[j][num] > 1 || boxes[box_index][num] > 1)
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
