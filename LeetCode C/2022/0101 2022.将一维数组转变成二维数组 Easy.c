/*
 * @lc app=leetcode.cn id=2022 lang=c
 *
 * [2022] 将一维数组转变成二维数组
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

/*
a是m*n二维矩阵,b是m*n个数组的一维矩阵
①a[i][j]映射到一维 :  x = i * n + j;
②b[x]还原到二维 : i = x / n, j = x % n;
*/
int **construct2DArray(int *original, int originalSize, int m, int n,
                       int *returnSize, int **returnColumnSizes) {
  if (m * n != originalSize)
  {
      *returnSize = 0;  // 返回行
      return NULL;
  }

  int **ar = (int**)malloc(sizeof(int*)*m); // M和N都未知，采用二级指针形式**ar，分配指针数组
  *returnColumnSizes = (int*)malloc(sizeof(int)*m);  // 动态申请二维数组中每一个行存储元素的个数

  for (int i = 0; i < m; i++) 
  {
      ar[i] = (int *)malloc(sizeof(int) * n);  // 分配每个指针所指向的数组
      (*returnColumnSizes)[i] = n;  // 返回列
  }
    
  for (int x = 0; x < originalSize; x++) {
    ar[x / n][x % n] = original[x];
  }
  *returnSize = m;
  return ar;
}
// @lc code=end
