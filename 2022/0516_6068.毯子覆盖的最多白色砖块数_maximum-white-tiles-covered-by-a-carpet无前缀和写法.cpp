/*
 * @lc app=leetcode.cn id=6068 lang=cpp
 *
 * [6068] 毯子覆盖的最多白色砖块数
 */

// @lc code=start
// greedy & slide window & two pointers 无prefixSum
class Solution
{
public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end()); // 像[56]那样，先按照各个区间的左端点排序
        long tmp = 0, cnt = 0;
        for (int i = 0, j = 0; i < tiles.size(); ++i)
        {
            while (j < tiles.size() && tiles[i][0] + carpetLen - 1 >= tiles[j][1])
            {
                tmp += tiles[j][1] - tiles[j][0] + 1;
                ++j;
            }
            // 毯子无法完全覆盖第j组砖块
            if (j < tiles.size())
                cnt = max(cnt, tmp + max(0, tiles[i][0] + carpetLen - 1 - tiles[j][0] + 1));
            // 毯子可以完全覆盖第j组砖块
            else
                cnt = max(cnt, tmp);
            tmp -= tiles[i][1] - tiles[i][0] + 1;
        }
        return cnt;
    }
};
// @lc code=end
