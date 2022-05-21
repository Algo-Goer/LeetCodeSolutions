/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
// BFS
class Solution
{
public:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc}); // 或q.emplace(sr, sc);
        image[sr][sc] = newColor;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == oldColor)
                {
                    q.push({nx, ny}); 
                    // 或q.emplace(nx, ny);
                    image[nx][ny] = newColor;
                }
            }
        }
        return image;
    }
};
// @lc code=end
