/*
 * @lc app=leetcode.cn id=1185 lang=c
 *
 * [1185] 一周中的第几天
 */

// @lc code=start

/*
蔡勒公式，基于公历（格里高利历）的置闰规则
W = [C/4] - 2C + y + [y/4] + [13 * (M+1) / 5] + d - 1
现在仍然让我们来算2004年5月1日的星期，显然C=20，y=4，M=5，d=1，代入蔡勒公式，有：
W = [20/4] - 40 + 4 + 1 + [13 * (5+1) / 5] + 1 - 1 = -15．
注意负数不能按习惯的余数的概念求余数，只能按数论中的余数的定义求余。
为了方便计算，我们可以给它加上一个7的整数倍，使它变为一个正数，比如加上70，得到55。
再除以7，余6，说明这一天是星期六。这和实际是一致的。
http://blog.sina.com.cn/s/blog_686f89820100jbi3.html
*/
char *dayOfTheWeek(int day, int month, int year) {
  int W, C, y;
  int mod;
  // 首先把年份拆分成C和y
  if (month == 1 || month == 2) {
    month += 12;
    year -= 1;
  }
  C = year / 100;
  y = year % 100;

  if (month >= 3) {
    W = (C / 4) - 2 * C + y + y / 4 + 13 * (month + 1) / 5 + day - 1;
    W += 7000;
    mod = W % 7;
    if (mod == 0)
      return "Sunday";
    if (mod == 1)
      return "Monday";
    if (mod == 2)
      return "Tuesday";
    if (mod == 3)
      return "Wednesday";
    if (mod == 4)
      return "Thursday";
    if (mod == 5)
      return "Friday";
    if (mod == 6)
      return "Saturday";
  }
  return "";
}
// @lc code=end
