class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        // 创建一个二维数组ans
        // ans[0]存储所有没有输掉任何比赛的玩家
        // ans[1]存储所有恰好输掉一场比赛的玩家
        vector<vector<int>> ans(2);
        map<int, int> w;
        map<int, int> l;
        for (auto &match : matches)
        {
            w[match[0]]++;
        }
        for (auto &match : matches)
        {
            l[match[1]]++;
        }
        for (auto &w_i : w)
        {
            if (l.find(w_i.first) == l.end())
            {
                ans[0].push_back(w_i.first);
            }
        }
        for (auto &l_i : l)
        {
            // 如果计数只有一次
            if (l_i.second == 1)
            {
                ans[1].push_back(l_i.first);
            }
        }
        // 对ans[0]和ans[1]分别按递增顺序排序，题目要求要读仔细
        return ans;
    }
};