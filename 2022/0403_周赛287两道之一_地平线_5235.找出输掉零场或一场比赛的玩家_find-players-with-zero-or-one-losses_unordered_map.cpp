/*
找出输掉零场或一场比赛的玩家
给你一个整数数组matches
其中matches[i]=[winneri, loseri]表示在一场比赛中winneri击败了loseri

返回一个长度为2的列表answer：
answer[0]是所有没有输掉任何比赛的玩家列表
answer[1]是所有恰好输掉一场比赛的玩家列表
两个列表中的值都应该按递增顺序返回

注意：
只考虑那些参与至少一场比赛的玩家
生成的测试用例保证不存在两场比赛结果相同
*/
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        // 创建一个二维数组ans
        // ans[0]存储所有没有输掉任何比赛的玩家
        // ans[1]存储所有恰好输掉一场比赛的玩家
        vector<vector<int>> ans(2);
        unordered_map<int, int> w;
        unordered_map<int, int> l;
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
        // 对ans[0]和ans[1]分别按递增顺序排序
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};