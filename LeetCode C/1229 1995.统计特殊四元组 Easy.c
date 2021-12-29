/*
 * @lc app=leetcode.cn id=1995 lang=c
 *
 * [1995] 统计特殊四元组
 */

// @lc code=start

// 枚举法
int countQuadruplets(int *nums, int numsSize) {
  int ans = 0;
  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      for (int k = j + 1; k < numsSize; k++) {
        for (int l = k + 1; l < numsSize; l++) {
          if (nums[i] + nums[j] + nums[k] == nums[l])
            ans++;
        }
      }
    }
  }
  return ans;
}
// @lc code=end
