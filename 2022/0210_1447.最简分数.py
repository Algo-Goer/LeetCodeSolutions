#
# @lc app=leetcode.cn id=1447 lang=python3
#
# [1447] 最简分数
#

# @lc code=start
# 分母i的范围是[2, n], 分子j的范围是[1, i - 1]
# 先求分子分母的最大公约数，约分后通过字符串判重
# Python的math模块gcd函数运用：gcd(x, y)= == 1，最大公约数为1时，x/y为最简分数
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        ans = []
        for i in range(2, n + 1):
            for j in range(1, i):
                if gcd(i, j) == 1:
                    ans.append(str(j) + '/' + str(i))
        return ans
# @lc code=end

