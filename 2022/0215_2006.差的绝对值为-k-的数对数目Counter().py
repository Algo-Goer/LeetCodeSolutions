#
# @lc app=leetcode.cn id=2006 lang=python3
#
# [2006] 差的绝对值为 K 的数对数目
#

# @lc code=start
'''
给你一个整数数组 nums 和一个整数 k
请你返回数对 (i, j) 的数目
满足 i < j 且 |nums[i] - nums[j]| == k 
'''
# 哈希表
'''
cnt记录nums中的数字出现的频次
遍历cnt对应的key,如果key+k也在nums中,那么(key, key+k)是一个数对,数对的个数为key的频次*(key+k)的频次
将其加入到ans中

只需要考虑key+k
因为和key差的绝对值为k的数字有key-k和key+k——如果key-k存在,那么数对(key,key-k)与(key,key+k)其实一样,只需要算一次
'''
import collections


class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        cnt = collections.Counter(nums)
        ans = 0
        for key in cnt:
            if key + k in cnt:
                ans += cnt[key] * cnt[key + k]
        return ans
        
# @lc code=end

