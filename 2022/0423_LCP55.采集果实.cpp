/*
欢迎各位勇者来到力扣新手村，本次训练内容为「采集果实」
在新手村中，各位勇者需要采集一些果实来制作药剂
time[i] 表示勇者每次采集1～limit颗第i种类型的果实需要的时间（即每次最多可以采集 limit 颗果实）
当前勇者需要完成「采集若干批果实」的任务
fruits[j] = [type, num]表示第j批需要采集num颗type类型的果实

采集规则如下：
按fruits给定的顺序依次采集每一批次
采集完当前批次的果实才能开始采集下一批次
勇者完成当前批次的采集后将清空背包
请计算并返回勇者完成采集任务最少需要的时间
*/

class Solution
{
public:
    int getMinimumTime(vector<int> &time, vector<vector<int>> &fruits, int limit)
    {
        int m = fruits.size();
        int t = 0;
        for (int i = 0; i < m; ++i)
        {
            int tmp = fruits[i][1];
            if (tmp % limit == 0)
                t += time[fruits[i][0]] * (tmp / limit);
            else
                t += time[fruits[i][0]] * (tmp / limit + 1);
        }
        return t;
    }
};