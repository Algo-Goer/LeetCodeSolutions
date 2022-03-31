/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
// 这道题和[852]区别在于，本题数组中可能包含多个峰值，题目中返回任何一个峰值所在位置即可
// 一次遍历，找到最大值 simulation
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        return max_element(nums.begin(), nums.end()) - nums.begin();
        /*
        max_element返回指定容器或数组范围[begin,end)内的最大值的迭代器或指针
        min_element返回指定容器或数组范围[begin,end)内的最小值的迭代器或指针
        注意返回的是迭代器或指针  
        不是直接返回值

        头文件： #include <algorithm>
        返回值： 两个函数返回的都是迭代器
        所以要提取数值的话需要在函数前加上*

        当使用std::min_element和std::max_element时
        如果范围中多于一个元素是最低/最高
        则返回的迭代器指向第一个这样的元素
        */
    }
};
// @lc code=end
