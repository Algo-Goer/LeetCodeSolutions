/*
 * @lc app=leetcode.cn id=1447 lang=c
 *
 * [1447] 最简分数
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int gcd(int x, int y)
{
    int t;
    while (y)
    {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}

char ** simplifiedFractions(int n, int* returnSize)
{
    char ** res = (char **)malloc(sizeof(char *) * n * (n + 1) / 2);
    // 开辟空间，最简分数最多只有(1 + n) * n / 2
    int pos = 0;
    for (int i = 2; i <= n; ++i)      // 分母
    {
        for (int j = 1; j <= i; ++j)  // 分子
        {
            int g = gcd(i, j);
            if (g == 1)               // 分母和分子的最大公约数为1，则该分数为最简分数
            {
                res[pos] = (char *)malloc(sizeof(char) * 20);
                sprintf(res[pos++], "%d/%d", j, i);             // sprintf()：将一个格式化的字符串输出到一个目的字符串中
            }
        }
    }
    *returnSize = pos;
    return res;
}
// @lc code=end

