/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
// code2 先判断长度大小以节省更多空间 & hashmap
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1); // intersect()表示两个数组的交集，intersect()的参数顺序不能错
        // 如果nums1长度大，那么就交换，这样空间复杂度可以最小
        unordered_map<int, int> m;
        for (int num : nums1)
        {
            ++m[num];
        }
        vector<int> intersection;
        for (int num : nums2)
        {
            if (m.count(num))
            {
                intersection.push_back(num);
                --m[num];
                /*
                下列代码在代码二中不可少
                否则会出现WA
                Testcase [4,9,5] [9,4,9,8,4]
                Answer   [9,4,9,4]
                Expected Answer  [4,9]

                或者也可以像代码一那样在push_back()前面加上if (m[num] > 0)的条件判断句
                */
                if (m[num] == 0)
                {
                    m.erase(num); // 删除num
                }
            }
        }
        return intersection;
    }
};
// @lc code=end
