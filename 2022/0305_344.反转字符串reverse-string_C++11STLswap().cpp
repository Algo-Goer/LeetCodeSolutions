/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
/*
题目要求原地修改输入数组、使用O(1)的额外空间
swap()
*/
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i)
            swap(s[i], s[n - 1 - i]);
        return;
    }
};
// @lc code=end

