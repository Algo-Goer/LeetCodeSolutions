/*
 * @lc app=leetcode.cn id=89 lang=c
 *
 * [89] 格雷编码
 */

// @lc code=start


/*
 * Note: The returned array must be malloced, assume caller calls free().
 * 二进制码B转格雷码G: G(n) = B(n+1) ^ B(n) (异或)
 * B(n+1)意味着右移1位，即i>>1
 */
int* grayCode(int n, int* returnSize)
{
    int totalSize = pow(2, n);
    int * ans = (int*)malloc(sizeof(int) * totalSize); // malloc()给名为ans的数组分配空间
    * returnSize = totalSize;

    for (int i = 0; i < totalSize; i++)
    {
        ans[i] = i ^ (i>>1);  // 核心代码
    }
    return ans;
}
// @lc code=end

