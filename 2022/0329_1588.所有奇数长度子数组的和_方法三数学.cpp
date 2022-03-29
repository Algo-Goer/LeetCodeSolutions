/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start
/*
类似2104.子数组范围和的贡献值思路
每个元素在多少个长度为奇数的子数组中出现
举例
arr=[1,4,2,5,3],n=5
对于2,加上本身左边有left=i+1=3个选择[1][4][2],其中偶数个数字的选择方案leftEven=(left+1)/2=2个[2][1,4,2],奇数个数字的选择方案leftOdd=left/2=1个[4,2]
对于2,加上本身右边有right=n-i=3个选择[2][5][3],其中偶数个数字的选择方案rightEven=(right+1)/2=2个[2][2,5,3],奇数个数字的选择方案rightOdd=right/2=1个[2,5]
每个数字一共在leftEven*rightEven+leftOdd*rightOdd个方案中出现
2一共在2*2+1*1=5个子数组中[2][1,4,2][4,2,5][2,5,3][1,4,2,5,3]

对于1,加上本身左边有left=i+1=1个选择[1],其中偶数个数字的选择方案leftEven=(left+1)/2=1个[1],奇数个数字的选择方案leftOdd=left/2=0个
对于1,加上本身右边有right=n-i=5个选择[1][4][2][5][3],其中偶数个数字的选择方案rightEven=(right+1)/2=3个[1][1,4,2][1,4,2,5,3],奇数个数字的选择方案rightOdd=right/2=2个[1,4][1,4,2,5]
每个数字一共在leftEven*rightEven+leftOdd*rightOdd个方案中出现
1一共在1*3+0=3个子数组中[1][1,4,2][1,4,2,5,3]
*/

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int res = 0;
        int len = arr.size();
        for (int i = 0; i < len; ++i)
        {
            int left = i + 1, right = len - i;
            int leftEven = (left + 1) / 2, leftOdd = left / 2;
            int rightEven = (right + 1) / 2, rightOdd = right / 2;
            res += (leftEven * rightEven + leftOdd * rightOdd) * arr[i];
        }
        return res;
    }
};
// @lc code=end
