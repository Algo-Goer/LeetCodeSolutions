/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start
/*
这道题很像第2104题贡献值-O(n)
今天先用O(n^3)枚举做这道题
*/
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int res = 0;
        for (int start = 0; start < arr.size(); ++start)
        {
            /*
            举例：
            start=0,length=1,end=0+1-1=0,[1]
            start=0,length=3,end=2,[1,4,2]
            start=0,length=5,end=4,[1,4,2,5,3]
            start=1,length=1,end=0,[4]
            ...
            */
            for (int length = 1; start + length <= arr.size(); length += 2)
            {
                int end = start + length - 1; // end是窗口的最后一个元素的索引
                for (int i = start; i <= end; ++i)
                {
                    res += arr[i];
                }
            }
        }
        return res;
    }
};
// @lc code=end
