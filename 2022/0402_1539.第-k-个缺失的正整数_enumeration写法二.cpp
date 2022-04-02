/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
/*
code2 enumeration写法二
思路跟[2195]一样，[2195]再多一两步
如果数组中没有<k的数，那么第k个缺失的数字就是k
如果有一个<=k的数，那么k++
最后返回k
*/
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] <= k)
                k++;
        }
        return k;
    }
};
// @lc code=end
