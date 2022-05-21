/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
// DFS
class Solution
{
public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor)
    {
        if (image[x][y] == oldColor)
        {
            image[x][y] = newColor;
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size())
                    dfs(image, nx, ny, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        if (oldColor != newColor)
        {
            dfs(image, sr, sc, oldColor, newColor);
        }
        return image;
    }
};
// @lc code=end
