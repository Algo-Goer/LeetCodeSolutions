/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version); 
/*
1 <= bad <= n <= 2^31 - 1
当一个版本为正确版本,则该版本之前的所有版本均为正确版本;
当一个版本为错误版本,则该版本之后的所有版本均为错误版本;
可以利用上述性质进行二分查找

将左右边界分别初始化为1和n,其中n是给定版本的数量
设定左右边界后,每次根据左右边界找到中间版本,检验其是否为正确版本:
如果该版本为正确版本,那么第一个错误的版本必然在该版本右侧,因此将左边界移动到该版本右侧;
否则第一个错误的版本必然位于该版本及该版本的左侧,因此将右边界移动到该版本左侧

每次移动边界时左右边界距离都变为原来一半,因此我们最多只需要缩O(logn)次
*/

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int left = 0;
        int right = n - 1;  // 有没有-1都可以AC
        /*
        这道题和第704题有区别:
        704不一定找到那个数,所以区间缩小到左右指针索引相等时,如果还没找到mid就返回-1
        为了不漏掉这个左右指针重合的情况,所以while (left <= right)中的等号不能遗漏,否则无法通过输入case为[5]这样的情况
        
        本题一定找得到第一个错误的版本
        */
        while (left <= right)  // 如果不取等号,输入case为5,4时输出为3WA而非正确答案4
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;    
    }
};
// @lc code=end

