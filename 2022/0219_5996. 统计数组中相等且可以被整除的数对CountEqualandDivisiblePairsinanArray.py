'''
给你一个下标从0开始长度为n的整数数组nums和一个整数k 
请你返回满足0<=i<j<n 
nums[i] == nums[j]且(i * j)能被k整除的(i, j)的数目对数
'''

'''
输入
nums = [3,1,2,2,2,1,3], k = 2
输出
4

总共有 4 对数符合所有要求
- nums[0] == nums[6] 且 0 * 6 == 0 能被 2 整除。
- nums[2] == nums[3] 且 2 * 3 == 6 能被 2 整除。
- nums[2] == nums[4] 且 2 * 4 == 8 能被 2 整除。
- nums[3] == nums[4] 且 3 * 4 == 12 能被 2 整除。
'''

class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        # 哈希表,用counter存储每个数字出现的次数
        counter = collections.Counter(nums)
        # 初始化结果
        res = 0
        # 遍历哈希表
        for key, value in counter.items():
            # 如果value大于1
            if value > 1:
                # 找出相同的数字对应的下标,并存人一个列表
                index = [i for i, x in enumerate(nums) if x == key]
                # 遍历index列表,如果有两个数字乘积能被k整除,则res+1
                for i in range(len(index) - 1):
                    for j in range(i + 1, len(index)):
                        if (index[i] * index[j]) % k == 0:
                            res += 1
        return res
        
# 一次性通过
                