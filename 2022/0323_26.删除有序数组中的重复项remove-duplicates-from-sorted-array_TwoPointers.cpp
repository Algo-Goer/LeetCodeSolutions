/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
/*
为了更好理解LeetCode2195.向数组中追加K个整数
来做这个删除重复项系列题目的
*/

/*
要求原地修改输入数组，且空间复杂度为O(1)
*/

/*
快指针：遍历数组到达的下标位置
慢指针：下一个不同元素要填入的下标位置
*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // 双指针
        int n = nums.size();
        if (n == 0)
            return 0;
        int fast = 1, slow = 1;
        while (fast < n)
        {
            if (nums[fast] != nums[fast - 1])
            {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};
// @lc code=end
