/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = 0;
        stack<int> s;
        // 新建newHeights数组，长度是heights.size()+2
        vector<int> newHeights(heights.size() + 2, 0);
        int n = newHeights.size();
        // 第一位和最后一位为0
        newHeights[0] = 0;
        newHeights[n - 1] = 0;
        // 拷贝
        for (int i = 1; i < heights.size() + 1; ++i)
        {
            newHeights[i] = heights[i - 1];
        }

        // 遍历
        for (int i = 0; i < newHeights.size(); ++i)
        {
            // 如果栈非空且当前元素<栈顶元素对应高度，则表示以栈顶元素对应高度为矩形的最大面积可以确定
            while (!s.empty() && newHeights[i] < newHeights[s.top()])
            {
                int cur = s.top();
                s.pop();
                int curHeight = newHeights[cur];
                // 栈顶元素pop出后，新栈顶元素就是其左边界
                int leftIdx = s.top();
                // 右边界就是当前下标
                int rightIdx = i;
                int curWidth = rightIdx - leftIdx - 1;
                ans = max(ans, curHeight * curWidth);
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end
