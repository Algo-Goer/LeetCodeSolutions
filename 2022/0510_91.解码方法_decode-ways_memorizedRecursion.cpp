/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
// Recursion & Memorization 直接递归会超时TLE
// base case：从后往前递归到只有一个字符时，只有1种解决方案
class Solution
{
public:
    unordered_map<int, int> memo;

    int numDecodings(string s)
    {
        return decode(s, s.size() - 1);
    }
    // 自定义函数
    int decode(string &s, int i)
    {
        // 记忆化
        if (memo.count(i))
        {
            return memo[i];
        }
        // 提示：可能有前导0，比如"06"，输出应该为0
        // Sanity Check 安全性检查，如果有非法情况直接返回
        /*
        Wrong Answer 21/269 cases passed (N/A)
        Testcase "06"
        Answer 1
        Expected Answer 0
        其他case "10011"
        补充代码
        */
        if (s.empty() || s[0] == '0')
            return 0;
        // 为了避免无限循环使得堆栈溢出-从后往前递归到只有第一个字符时，只有1种解决方案
        if (i <= 0)
            return 1;

        int cnt = 0;

        char cur = s[i];
        char pre = s[i - 1];

        if (cur > '0') // 排除10、20  1~9
        {
            cnt = decode(s, i - 1);
        }

        if (pre == '1' || pre == '2' && cur <= '6') // 10~26
            cnt += decode(s, i - 2);

        memo[i] = cnt;

        return cnt;
    }
};
// @lc code=end
