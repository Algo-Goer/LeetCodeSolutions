/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
// code2 
/*
要想找到下一个更大元素，要从最低位（从后往前）遍历
先从后往前找到第一个小于后面数字的数，记下标为i
从后往前找到第一个大于s[i]的数，记下标为j
交换s[i]和s[j]
将i+1到末尾的数从小到大排序
*/
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        int len = s.size();
        if (len < 2)
            return -1;
        int i = len - 2;
        for (; i >= 0; --i)
        {
            if (s[i] < s[i + 1])
            {
                break;
            }
        }
        if (i == -1)
            return -1;
        int j = len - 1;
        for (; j >= 0; --j)
        {
            if (s[j] > s[i])
            {
                swap(s[i], s[j]);
                break;
            }
        }
        sort(s.begin() + i + 1, s.end()); // 将i+1到末尾的数从小到大排序
        long long res = stoll(s);
        if (res > INT_MAX)
            return -1;
        return res;
    }
};
// @lc code=end
