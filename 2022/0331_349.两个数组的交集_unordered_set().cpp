/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
// unordered_set()
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s1, s2;  // 无序不重复的集合
        for (auto i : nums1)
            s1.insert(i);
        for (auto i : nums2)
            s2.insert(i);
        set<int> ans;
        for (auto i : nums1) // 遍历nums1数组,如果在nums2数组中找到nums1的元素就将其放入ans中
        {
            if (s2.find(i) != s2.end())
                ans.insert(i);
        }
        for (auto i : nums2)
        {
            if (s1.find(i) != s1.end())
                ans.insert(i);
        }
        return vector<int>(ans.begin(), ans.end()); // 将ans集合转换为vector
        // 直接return ans;会出现Compile Error,因为最上面public后面写的是返回vector类型
    }
};
// @lc code=end

