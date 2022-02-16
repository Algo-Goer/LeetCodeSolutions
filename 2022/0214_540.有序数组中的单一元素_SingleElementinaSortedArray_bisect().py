#
# @lc app=leetcode.cn id=540 lang=python3
#
# [540] 有序数组中的单一元素
#

# @lc code=start
'''
给你一个仅由整数组成的有序数组,其中每个元素都会出现两次,唯有一个数只会出现一次
请你找出并返回只出现一次的那个数
你设计的解决方案必须满足O(log n)时间复杂度和O(1)空间复杂度。
'''
# O(log n)时间复杂度--二分查找、相邻--异或运算
# 可以用Python标准库中的bisect模块构建高性能的二分搜索方案
# 用key function lambda x: nums[x] != nums[x ^ 1]，寻找第一个True的位置

'''
Python 3.10.2 Documentation >> Python标准库 >> bisect --- 数组二分查找算法
bisect在很长的有序序列中可快速查找一个元素的index
bisect.bisect_left(a,x,low=0,high=len(a),*,key=None)
在a中找到x合适的插入点以维持有序。low和high指定搜索范围,默认整个列表
key指定带有单个参数的key function,用于从每个输入元素中提取比较key,默认None(直接比较元素)
'''
from bisect import bisect

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        return nums[bisect_left(range(len(nums) - 1), True, key = lambda x: nums[x] != nums[x ^ 1])]
        # 易错点：return nums[bisect_left(range(len(nums)-1), True, 0, len(nums), key = lambda x: nums[x] != nums[x ^ 1])]会Runtime Error:IndexError: range object index out of range
        # 因为x和x^1,所以x最多取len(nums)-2,x^1最多取len(nums)-1
        # 又因为Python中range取头不取尾,所以[0, len(nums) - 1]



# @lc code=end

