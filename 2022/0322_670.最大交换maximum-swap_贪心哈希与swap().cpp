/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
/*
贪心+哈希
低位大数与高位小数交换
最多只能交换一次

特殊情况先考虑：如果数字已经递减排列，那么直接返回该值
*/
class Solution
{
public:
    int maximumSwap(int num)
    {
        unordered_map<int, int> m;
        string nums = to_string(num);
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i] - '0'] = i; // nums[i] - '0' 表示char转换为int
            // 2736, m[2] = 0, m[7] = 1, m[3] = 2, m[6] = 3
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 9; j > nums[i] - '0'; --j)
            {
                if (m.count(j) && m[j] > i) // 判断是否存在该字符且该字符的索引大于当前索引
                {
                    swap(nums[i], nums[m[j]]); // swap()时间复杂度O(1)，空间复杂度O(1)
                    return stoi(nums);         // stoi()时间复杂度O(n)，空间复杂度O(1)
                    // 最多可以交换一次，所以swap后直接return
                }
            }
        }
        return num;
    }
};
// @lc code=end
