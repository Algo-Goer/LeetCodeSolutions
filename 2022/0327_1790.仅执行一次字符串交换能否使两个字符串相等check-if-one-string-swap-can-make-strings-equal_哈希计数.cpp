/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
// 哈希计数、字符串
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int n = s1.size();
        if (n != s2.size())
            return false;
        if (s1.compare(s2) == 0) // compare()返回0表示两个字符串相等，返回1表示s1>s2，返回-1表示s1<s2
                                 // compare()时间复杂度O(n)，空间复杂度O(1)
            return true;
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
                cnt++;
        }
        if (cnt != 2) // 最多仅执行一次字符串交换，说明两字符串最多只有两个字符位置不同
            return false;
        unordered_map<char, int> m;
        for (auto &ch : s1)
        {
            m[ch]++;
        }
        for (auto &ch : s2)
        {
            m[ch]--;
        }
        for (auto &it : m)
        {
            if (it.second != 0)
                return false;
        }
        return true;

        /*
        int n = s1.size();
        if (n != s2.size())
            return false;
        unordered_map<char, int> cnt;
        for (auto &ch : s1)
        {
            cnt[ch]++;
        }
        for (auto &ch : s2)
        {
            cnt[ch]--;
        }
        for (auto &it : cnt)
        {
            if (it.second != 0)
                return false;
        }
        return true;

        没注意到仅执行一次交换条件
        Wrong Answer
        111/130 cases passed (N/A)
        Testcase "abcd" "dcba"
        Answer true
        Expected Answer false
        */
    }
};
// @lc code=end
