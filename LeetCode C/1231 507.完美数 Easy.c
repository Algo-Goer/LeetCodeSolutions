/*
 * @lc app=leetcode.cn id=507 lang=c
 *
 * [507] 完美数
 */

// @lc code=start

bool checkPerfectNumber(int num) {
  int sum = 1;
  if (num <= 1)
    return false;
  for (int d = 2; d * d <= num; d++) {
    if (num % d == 0) {
      sum += d;
      sum += num / d;
    }
  }
  return num == sum;
}
// @lc code=end
