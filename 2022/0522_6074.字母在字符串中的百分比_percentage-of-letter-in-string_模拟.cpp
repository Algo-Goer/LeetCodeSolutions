/*
字母在字符串中的百分比
给你一个字符串 s 和一个字符 letter ，返回在 s 中等于 letter 字符所占的 百分比 ，向下取整到最接近的百分比。

输入：s = "foobar", letter = "o"
输出：33
解释：
等于字母 'o' 的字符在 s 中占到的百分比是 2 / 6 * 100% = 33% ，向下取整，所以返回 33 。
*/
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        int cnt = 0;
        for (auto c : s)
        {
            if (c == letter)
                cnt++;
        }
        return cnt * 100 / n;
    }
};  