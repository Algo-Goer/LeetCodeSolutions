# @before-stub-for-debug-begin
from python3problem412 import *
from typing import *
# @before-stub-for-debug-end

#
# @lc app=leetcode.cn id=412 lang=python3
#
# [412] Fizz Buzz
#

# @lc code=start
# 时间复杂度O(n):遍历O(n),判断是否能被整除O(1)
# 空间复杂度O(n)：输出大小为n的数组
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = [] # 初始化一个空答案列表
        for i in range (1, n + 1):  # 必须是n + 1，否则对n不会输出判断结果
            s = ""
            if i % 3 == 0:
                s += "Fizz"
            if i % 5 == 0:
                s += "Buzz"
            if s == "":
                s = str(i)
            ans.append(s)
        return ans


# @lc code=end

