/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字
 */

// @lc code=start
/*
贪心
最多只能翻转一次：
尽量翻转高位，从6到9
*/
class Solution
{
public:
    int maximum69Number(int num)
    {
        // 把num转换成string
        string nums = to_string(num);
        // 从左到右遍历，找到第一个6翻转为9
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == '6')
            {
                nums[i] = '9';
                break; // 只能翻转一次
            }
        }
        return stoi(nums);
    }
};
// @lc code=end
