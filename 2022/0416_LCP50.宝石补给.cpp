/*
每位勇者初始都拥有一些能量宝石
gem[i]表示第i位勇者的宝石数量
现在这些勇者们进行了一系列的赠送
operations[j] = [x, y]表示在第 j 次的赠送中 第 x 位勇者将自己一半的宝石（按需向下取整）赠送给第 y 位勇者
在完成所有的赠送后
请找到拥有最多宝石的勇者和拥有最少宝石的勇者并返回他们二者的宝石数量之差

注意：
赠送将按顺序逐步进行。
例如：
输入：gem = [3,1,2], operations = [[0,2],[2,1],[2,0]]
输出：2
解释：
第 1 次操作，勇者 0 将一半的宝石赠送给勇者 2， gem = [2,1,3]
第 2 次操作，勇者 2 将一半的宝石赠送给勇者 1， gem = [2,2,2]
第 3 次操作，勇者 2 将一半的宝石赠送给勇者 0， gem = [3,2,1]
返回 3 - 1 = 2
*/

class Solution
{
public:
    int giveGem(vector<int> &gem, vector<vector<int>> &operations)
    {
        int n = gem.size();
        for (int i = 0; i < operations.size(); ++i)
        {
            int x = operations[i][0];
            int y = operations[i][1];
            int tmp = gem[x] / 2;
            gem[x] -= tmp;
            gem[y] += tmp;
        }
        sort(gem.begin(), gem.end());
        return gem[n - 1] - gem[0];
    }
};