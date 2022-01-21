/*
 * @lc app=leetcode.cn id=575 lang=c
 *
 * [575] 分糖果
 */

// @lc code=start

/*
 * 先排序，再统计出有多少非重复元素count
 * 能吃的糖果数量canEat=糖果数除以2
 * 若count<=canEat,return count;反之return canEat
 * C语言中自带函数库中就有快速排序——qsort函数，包含在 <stdlib.h> 头文件中
 */
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); // 两函数比较
}
int distributeCandies(int *candyType, int candyTypeSize)
{
    qsort(candyType, candyTypeSize, sizeof(int), cmpfunc); // 数组排序好
    int count = 1;
    int lastCandy = candyType[0];
    for (int i = 1; i < candyTypeSize; ++i)
    {
        if (candyType[i] != lastCandy)
        {
            count++;
            lastCandy = candyType[i];
        }
    }
    int canEat = candyTypeSize / 2;  // 题目中说明candyTypeSize为偶数
    return count <= canEat ? count : canEat;
}
// @lc code=end
