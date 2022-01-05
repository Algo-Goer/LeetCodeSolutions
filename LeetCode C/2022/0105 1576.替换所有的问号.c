/*
 * @lc app=leetcode.cn id=1576 lang=c
 *
 * [1576] 替换所有的问号
 */

// @lc code=start

char *modifyString(char *s) {
  for (int i = 0; i < strlen(s); ++i) {
    if (s[i] == '?') {
      for (char ch = 'a'; ch <= 'c'; ++ch) {
        if ((i > 0 && s[i - 1] == ch) ||(i < strlen(s) - 1 && s[i + 1] == ch)) {
          continue;
        }
        s[i] = ch;
      }
    }
  }
  return s;
}
// @lc code=end
