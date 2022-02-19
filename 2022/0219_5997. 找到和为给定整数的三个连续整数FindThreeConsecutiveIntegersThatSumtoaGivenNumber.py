'''
给你一个整数num 
请你返回三个连续的整数
它们的和为num
如果num无法被表示成三个连续整数的和
请你返回一个空数组
0 <= num <= 10^15
'''

class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        res = []
        if num % 3 == 0:
            res.append(num // 3 - 1)
            res.append(num // 3)
            res.append(num // 3 + 1)
            return res
        else:
            return []
        
