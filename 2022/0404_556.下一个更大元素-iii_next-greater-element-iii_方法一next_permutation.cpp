/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
// code1 类[31]下一个排列 next_permutation()
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        if (stoll(s) <= n || stoll(s) > INT_MAX)
            return -1;
        return stoi(s);
    }
};
// @lc code=end
