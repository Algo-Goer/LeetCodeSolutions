/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
returnColumnSizes	        //是一维数组的地址的地址（地址即指针）
* returnColumnSizes		    //是一维数组的地址
(* returnColumnSizes)[i]	//是一维数组的i个元素
*/
/*
首先大家要知道这个 returnColumnSizes 在主函数中应该是一个一维数组
每个元素代表了当前排有多少个有效的列
一般这种题会有一个配套的 returnSize 代表共有多少排
这个一维数组，配合着排的总数
*/

// 双指针i、j

/* 
要通过一个函数改变一个数的值
就必须用一个指针
这意味要改变一个数组的值
就必须用一个二级指针
*/

int compfunc(const void *a, const void *b)
{
    int **x = (int **)a;
    int **y = (int **)b;
    return **x - **y;
}
// int** intervals是题目给定的区间集合
// int intervalsSize是区间集合-二维数组的行数，也就是总共的区间个数
// int* intervalsColSize是每一行的列数，就是二维数组中每一个一维数组的长度，本题中都为2
// int* returnSize是返回的区间集合-二维数组的行数，也就是最终的区间个数
// int** returnColumnSizes是一个指向一维数组int*的指针，所以是int**，这个一维数组中存的是你返回的二维数组的每一行的列数，本题中为2
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    qsort(intervals, intervalsSize, sizeof(int*), compfunc);
    int i, j, k;
    int **res = (int **)malloc(sizeof(int *) * intervalsSize);        
    *returnColumnSizes = (int *)malloc(sizeof(int) * intervalsSize);  // 返回的二维数组的每一行的列数
    *returnSize = 0;                                                  // 初始化，返回的二维数组行数为0，二维数组初始为空
    // 对各区间按照起始点排序
    for (i = 0; i < intervalsSize; ++i)
    {
        res[i] = (int *)malloc(sizeof(int) * 2);
        res[i][0] = intervals[i][0];
        res[i][1] = intervals[i][1];
    }
    for (i = 0; i < intervalsSize; ++i)
    {
        for (j = i + 1; j < intervalsSize; ++j)
        {
            if (res[i][1] >= res[j][0])
            {
                res[i][1] = res[j][1] > res[i][1] ? res[j][1] : res[i][1];  // 更新res中的最大值
                res[j][0] = -1;     // 0 <= starti <= endi <= 10^4
            }
        }
    }
    for (i = 0; i < intervalsSize; ++i)
    {
        if (res[i][0] != -1)
        {
            res[*returnSize] = res[i];                     // 将res中的有效区间放入返回的二维数组中
            (*returnColumnSizes)[*returnSize] = 2;         // 返回的二维数组每一行的列数均为2
            (*returnSize)++;                               // 返回的二维数组行数+1
        }                           
    }
    return res;
}
// @lc code=end

