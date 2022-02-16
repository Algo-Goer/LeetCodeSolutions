/*
 * @lc app=leetcode.cn id=1380 lang=c
 *
 * [1380] 矩阵中的幸运数
 */

// @lc code=start

/**
 * 思路:
 * 每行最小值数组min_row,每列最大值数组max_col
 * min_row[i]表示第i行的最小值,max_col[j]表示第j列的最大值
 * 遍历矩阵,如果min_row[i] == max_col[j] == nums[i][j]
 * 那nums[i][j]就是幸运数
 * 
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int row[matrixSize];
    for (int i = 0; i < matrixSize; i++)
    {
        row[i] = matrix[i][0];                  // 第i行的第1列
    }
    int col[*matrixColSize];                    // 相当于matrixColSize[0]
    for (int j = 0; j < *matrixColSize; j++)
    {
        col[j] = matrix[0][j];                  // 第1行的第j列
    }
    for (int i = 0; i < matrixSize; i++)
    {
        for(int j = 0; j < *matrixColSize; j++)
        {
            row[i] = row[i] > matrix[i][j] ? matrix[i][j] : row[i];   // 第i行的最小值
            col[j] = col[j] < matrix[i][j] ? matrix[i][j] : col[j];   // 第j列的最大值
        }
    }
    int *res = (int *)malloc(sizeof(int) * matrixSize);
    int res_size = 0;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            if (row[i] == col[j] && row[i] == matrix[i][j])
            {
                res[res_size++] = matrix[i][j];
            }
        }
    }
    *returnSize = res_size;
    return res;
}
// @lc code=end

