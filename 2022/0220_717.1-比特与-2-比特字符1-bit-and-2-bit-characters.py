#
# @lc app=leetcode.cn id=717 lang=python3
#
# [717] 1比特与2比特字符
#

# @lc code=start
'''
有两种特殊字符
第一种字符可以用一个比特0来表示
第二种字符可以用两个比特(10或11)来表示

给定一个以0结尾的二进制数组bits
如果最后一个字符必须是一位字符则返回 true 
'''

'''
出现1,必须组成10或11,所以跳过1位
出现0,必须是第一种字符
'''


class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i, n = 0, len(bits)
        while i < n - 1:  
            if bits[i] == 1:
                i += 2
            else:
                i += 1
        return i == n - 1   
        # 如果i等于n-1,说明最后一位是0,bool值为True,否则为False

# @lc code=end

