/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
//  哈希表、数学
class Solution
{
public:
    // 分离数字计算各个数字平方和
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int sum = 0;
        unordered_set<int> set;
        while (n != 1)
        {
            sum = getSum(n);
            if (set.find(sum) != set.end()) // 如果已经存在，则说明出现了循环，返回false
                return false;
            set.insert(sum); // 否则添加到集合中
            n = sum;
        }
        return true;
    }
};
// @lc code=end
