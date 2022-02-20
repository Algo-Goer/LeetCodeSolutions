#
# @lc app=leetcode.cn id=969 lang=python3
#
# [969] 煎饼排序
#

# @lc code=start

class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        res = []
        # 当arr非空时
        while arr:                      # 3241 
            a = max(arr) 
            idx = arr.index(a)
            k = idx + 1                                    # k=3  
            res.append(k)
            res.append(len(arr))                           # 4  
            arr = (arr[:k][::-1] + arr[k:])[::-1][:-1]      # arr[:k][::-1] 423
            # arr[:k][::-1]表示从0到k-1的元素进行反转        # arr[k:]表示从k到最后的元素1 # 4231 # [::-1]1324 [:-1]去除最后一个元素后的数组
            # arr[k:]表示从k到最后一个元素
        return res
        

    
# @lc code=end

