/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 */

// @lc code=start
/*
code1 enumeration写法一
数组长度小，方法一枚举法
这道题让我想起周赛的一道题[2195]，也是缺失数字题，目前对这类题还是不熟练，需要多练习

由于arr数组最大数字不超过1000，k不超过1000，所以返回答案不超过2000,
可以把数组开大一些，然后遍历arr数组，将出现的元素标记为0
查找第k个不为0的元素
*/
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans(2022, 0);
        for (int i = 1; i <= 2000; ++i)
        {
            ans[i] = i; // ans[1]=1, ans[2]=2 ...
        }
        for (int i = 0; i < n; ++i)
        {
            ans[arr[i]] = 0; // arr=[1,2,3,4]  ans[1]=0, ans[2]=0 ...
        }
        for (int i = 1; i <= 2000; ++i)
        {
            if (ans[i] != 0) // 5 6
            {
                k--;        // k=1
                if (k == 0) // k=0
                {
                    return i; // i = 6
                }
            }
        }
        return 0;
    }
};
// @lc code=end
