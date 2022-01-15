/*
 * @lc app=leetcode.cn id=1716 lang=c
 *
 * [1716] 计算力扣银行的钱
 */

// @lc code=start

int totalMoney(int n)
{
    int week = n / 7; // 完整的一周 有几周
    int day = n % 7;  // 余数第几天
    int sumOfMoney = 0;
    if (n <= 7)
    {
        sumOfMoney = (1 + n) * n / 2;
    }
    else
    {
        // 每多完整的一周，就比上一周多7天
        for (int i = 1; i <= week; i++)
        {
            sumOfMoney += 28 + 7 * (i - 1); // 整除的部分，另外不要写成week-1
        }
        sumOfMoney += (1 + day) * day / 2 + week * day; // 余数的部分
    }
    return sumOfMoney;
}
// @lc code=end
