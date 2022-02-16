'''
题目:
给你一个下标从0开始的数组nums,该数组由n个正整数组成。

如果满足下述条件,则数组nums是一个交替数组:
nums[i - 2] == nums[i],其中 2 <= i <= n - 1 。
nums[i - 1] != nums[i],其中 1 <= i <= n - 1 。
在一步操作中,你可以选择下标i并将nums[i]更改为任一正整数。

返回使数组变成交替数组的最少操作数。
'''

'''
思路:
1、把原有数组分成奇数组和偶数组
2、分别统计各组数字出现的次数,找出最大次数
3、如果两组最大次数对应的数字不同,则操作次数=数组大小-奇数组最高频次-偶数组最高频次
4、如果两组最大次数对应的数字相同,则挑选次多次数对应的元素(试验两次,看哪次次数更少):
比较并取min:
操作次数=数组大小-奇数组最高频次-偶数组次高频次
操作次数=数组大小-偶数组最高频次-奇数组次高频次

注意:1 <= nums.length <= 10^5,所以要考虑特殊情况长度为1的数组
'''

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        oddNums = nums[::2]  # 切片，从第一个[下标0]元素开始，步长为2
        evenNums = nums[1::2]  # 切片，从第二个[下标1]的元素开始，步长为2
        '''
        利用collections.Counter()函数,统计列表中每个元素出现的次数
        most_common([n])会按照次序返回映射里最常见的n个键和它们的计数
        '''
        # 字典
        dicOdd = Counter(oddNums).most_common()
        dicEven = Counter(evenNums).most_common()

        # 字典中key与value相分离:加*表示Unpack/解构
        # Python三元表达式
        # 当字典长度小于2时第二个元组就用(0, 0)代替，也就是次大频次为0
        # 当数组长度为1（题目允许）时，dicEven[0] = (0, 0)填充
        keyOdd1, valueOdd1 = dicOdd[0]                                     # 最大频次奇数元组
        keyOdd2, valueOdd2 = dicOdd[1]  if len(dicOdd) > 1 else (0, 0)   # 次大频次奇数元组
        keyEven3, valueEven3 = dicEven[0] if dicEven else (0, 0)            # 最大频次偶数元组
        keyEven4, valueEven4 = dicEven[1]  if len(dicEven) > 1 else (0, 0) # 次大频次偶数元组

        if keyOdd1 != keyEven3:
            return len(nums) - valueOdd1 - valueEven3
        else:
            return min(len(nums) - valueOdd1 - valueEven4, len(nums) - valueOdd2 - valueEven3)
        