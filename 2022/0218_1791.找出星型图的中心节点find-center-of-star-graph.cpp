/*
 * @lc app=leetcode.cn id=1791 lang=cpp
 *
 * [1791] 找出星型图的中心节点 find-center-of-star-graph
 */

// @lc code=start
/**
 * 有一个无向的星型图，由n个编号从1到n的节点组成
 * 星型图有一个中心节点
 * 并且恰有n-1条边将中心节点与其他每个节点连接起来
 * 给你一个二维整数数组edges
 * 其中edges[i] = [ui, vi]表示在节点 ui 和 vi 之间存在一条边
 * 请你找出并返回edges所表示星型图的中心节点
 */

/*
edges数组前两个元素表示边的起点和终点
相互比较,共4次
相同的点，则是中心节点
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        int u = edges[0][0];
        int v = edges[0][1];
        int s = edges[1][0];
        int t = edges[1][1];
        if (u == s || u == t)
            return u;
        else 
            return v;
    }
};
// @lc code=end

