/*
 * @lc app=leetcode.cn id=1614 lang=c
 *
 * [1614] 括号的最大嵌套深度
 */

// @lc code=start


// MAX()作为宏定义实现，这样可以不用区分数据类型，比如整数还是浮点型
#define MAX(a,b) ((a)>(b))?(a):(b)

int maxDepth(char *s) {
  int ans = 0;
  int depth = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '(') {
      depth++;
      ans = MAX(depth, ans);
    }

    else if (s[i] == ')')
      depth--;
  }
  return ans;
}
// @lc code=end
