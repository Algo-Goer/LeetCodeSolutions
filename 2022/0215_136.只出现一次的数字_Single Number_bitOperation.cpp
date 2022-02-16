/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

/**
 * @brief 
 * 给定一个非空整数数组
 * 除了某个元素只出现一次以外
 * 其余每个元素均出现两次
 * 找出那个只出现了一次的元素。
 * 
 * 你的算法应该具有线性时间复杂度
 * 你可以不使用额外空间来实现吗
 */
// @lc code=start
/**
 * @brief 位运算/异或运算,第540题有序数组中的单一元素也可以用这个方法
 * 一个数和它本身做异或运算结果为 0，即 a ^ a = 0;一个数和 0 做异或运算的结果为它本身，即 a ^ 0 = a
 * 我们只要把所有数字进行异或
 * 成对儿的数字就会变成 0
 * 落单的数字和 0 做异或还是它本身
 * 所以最后异或的结果就是只出现一次的元素
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res ^= nums[i];
        }
        return res;
    }
};
// @lc code=end

