/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
/*
题目要求：
1、去重
2、去重字符串的字符顺序不能打乱s中字符出现的相对顺序
3、字典序最小，比如'bcabc'，'bca'和'abc'中，前者符合前两个条件，后者符合三个条件，所以为'abc'

使返回结果的字典序最小
思路抽象为：ASCII码小的字母在前面。找右边下一个ASCII更小的字符进行替换，且不重复字符，所以单调栈就要从栈底到栈顶严格递增
但因为还有个条件：每个字母只出现一次，所以如果一个字符频次只为1或者剩下频次为1，就算不满足上面的栈条件，也得push入栈

贪心：
把该字母与之前的字母逐一比对：
如果发现该字母比之前的字母大或或栈空，就暂时push入栈
反之，且之前的字母出现不止一次，就pop栈顶元素

循环，直到栈空或遍历结束

贪心&单调栈，类同题目LeetCode_1081_不同字符的最小子序列

举例：[b, c, a, b, c] - 严格单调递增栈 - 找下一个ASCII码更小的元素
1、栈空，直接push，stack:[b]
2、c > 栈顶元素b，直接push，stack:[b, c]
3、a < 栈顶元素c，且c后面还会出现，所以pop出c，stack:[b]
4、a < 栈顶元素b，且b后面还会出现，所以pop出b，stack:[]
5、栈空，直接push，stack:[a]
6、b > 栈顶元素a，直接push，stack:[a, b]
7、c > 栈顶元素b，直接push，stack:[a, b, c]

举例：[c, b, a, c, d, c, b, c] - 严格单调递增栈 - 找下一个ASCII码更小的元素
1、栈空，直接push，stack:[c]
2、b < 栈顶元素c，且c后面还会出现，所以pop出c，stack:[]
3、栈空，直接push，stack:[b]
4、a < 栈顶元素b，且b后面还会出现，所以pop出b，stack:[]
5、栈空，直接push，stack:[a]
6、c > 栈顶元素a，直接push，stack:[a, c]
7、d > 栈顶元素c，直接push，stack:[a, c, d]
8、c < 栈顶元素d，但是d后面不会再出现，所以不会pop出d，而c已经在stack中，因此跳过
9、b < 栈顶元素d，但是d后面不会再出现，所以不会pop出d，而b后面也不会再出现，所以直接push，stack:[a, c, d, b]
10、c > 栈顶元素b，但是c已经在stack中，因此跳过，stack:[a, c, d, b]

易错点：
1、每pop一次，记得计数-1
2、以下WA说明：当满足`c > st.top()`时，要附加一句：如果stack中已经有c，那么就跳过该元素
输入
"cbacdcbc"
输出
"acdbc"
预期结果
"acdb"

*/
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char, int> mp;   // 统计字符出现次数
        string res;                    // 用字符串模拟单调栈
        vector<bool> visit(26, false); // 记录该字符是否在栈中
        for (char c : s)
        {
            mp[c]++;
        }
        for (char c : s)
        {
            if (!visit[c - 'a'])
            {
                // 未出现在栈中，才考虑入栈
                while (!res.empty() && res.back() > c && mp[res.back()] > 0)
                {
                    visit[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                visit[c - 'a'] = true;
            }
            mp[c]--;
        }
        return res;
    }
};
// @lc code=end
