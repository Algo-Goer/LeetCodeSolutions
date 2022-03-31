/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

/*
设选出的数字为pick，猜测的数字为x，若guess(x)<=0，说明pick<=x，否则pick>x
二分查找来求出答案pick
设区间为[left, right]，初始时left=1，right=n
设中间元素mid
若guess(mid)<0，说明pick∈[left, mid-1];
若guess(mid)>0, 说明pick∈[mid+1, right];
若guess(mid)=0, 说明pick=mid
当区间左右端点相同时，我们找到了答案，退出循环
*/

/*
举例
n=10, pick=6
left=1, right=10, mid=5<pick=6
guess(mid)=1, left=mid+1=6
left=6, right=10, mid=8>pick=6
guess(mid)=-1, right=mid-1=7
left=6, right=7, mid=6
guess(mid)=0
返回6

n=1, pick=1
left=1=right=1, 不进入while循环
返回left=1
*/
class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1, right = n;
        while (left < right) // 和之前做过的所有二分查找题取等号不同，本题只有left==right时，才找到pick答案，所以这里不取等号
        {
            int mid = left + (right - left) / 2;
            if (guess(mid) < 0)
                right = mid - 1; // 说明pick∈[left, mid-1]
            else if (guess(mid) > 0)
                left = mid + 1; // pick∈[mid+1, right]
            else
                return mid;
        }
        // left==right，区间缩为一个点即pick答案
        return left; // 一定要有个返回值，否则报错
    }
};
// @lc code=end
