/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
// 方法二 two pointers
/*
举例
numbers=[5,25,75], target=100
left=0, right=2
numbers[left]+numbers[right]=5+75=80 < target
left=1
left=1, right=2
numbers[left]+numbers[right]=25+75=100 = target
return [2, 3]
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (left <= right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
                return {left + 1, right + 1};
            else if (sum < target)
                ++left;
            else
                --right;
        }
        return {0, 0};
    }
};
// @lc code=end
