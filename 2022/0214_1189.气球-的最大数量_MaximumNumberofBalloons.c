/*
 * @lc app=leetcode.cn id=1189 lang=c
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
/**
 * 思路：
 * 哈希、计数
 * 字母balloon需要2个l和o，可把字母l和o的数量分别除以2，返回min{各个字母数量}即可以构成单词的数量
 */
// C写qsort()函数前要自定义comp()函数
// qsort()函数从小到大即升序排序
int compfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;      // 强制转换类型
}

int maxNumberOfBalloons(char * text)
{
    int cnt[5];    // 空间复杂度O(c)
    memset(cnt, 0, sizeof(cnt));  // 字母统计经常要用到memset()，三个参数，初始化为0
    for (int i = 0; text[i] != '\0'; i++)
    {
        switch (text[i])
        {
            case 'b':
                cnt[0]++;
                break;
            case 'a':
                cnt[1]++;
                break;
            case 'l':
                cnt[2]++;
                break;
            case 'o':
                cnt[3]++;
                break;
            case 'n':
                cnt[4]++;
                break;
        }
    }
    cnt[2] /= 2;   // 全部遍历后再除以2
    cnt[3] /= 2;
    qsort(cnt, 5, sizeof(int), compfunc);
    return cnt[0];  // 返回最小值
}

    
// @lc code=end

