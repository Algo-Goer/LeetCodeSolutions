/*
 * @lc app=leetcode.cn id=6068 lang=cpp
 *
 * [6068] 毯子覆盖的最多白色砖块数
 */

// @lc code=start
// greedy & slide window & two pointers & prefix sum
class Solution
{
public:
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end()); 
        int n = tiles.size();
        vector<int> presum(n, 0);
        for (int i = 0; i < n; ++i)
        {
            presum[i] = (i == 0 ? 0 : presum[i - 1]) + (tiles[i][1] - tiles[i][0] + 1);
        }
        int j = 0;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            while (j < n && tiles[i][0] + carpetLen - 1 >= tiles[j][1])
            {
                ++j;
            }
            int len = presum[j - 1] - (i == 0 ? 0 : presum[i - 1]);
            if (j < n)
            {
                len += max(0, tiles[i][0] + carpetLen - 1 - tiles[j][0] + 1);
            }
            res = max(res, len);
        }
        return res;
    }
};
// @lc code=end
