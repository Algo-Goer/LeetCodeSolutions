/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
/*
BF算法(Brute-Force，最基本的字符串匹配算法)
定义两个索引值i和j
分别指示主串Tag和子串Ptn当前正待比较的字符位置
从主串Tag的第pos个字符起和子串Ptn的第一个字符比较
若相等
则继续逐个比较后续字符
否则从主串Tag的下一个字符起再重新和子串Ptn的字符进行比较
重复执行
直到子串Ptn中的每个字符依次和主串Tag中的一个连续字符串相等
则匹配成功
函数返回该连续字符串的第一个字符在主串Tag中的位置
否则匹配不成功
函数返回-1
*/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if (n == 0)
            return 0;
        // BF算法
        for (int i = 0; i < m - n + 1; ++i)
        {
            int j = 0;
            for (; j < n; ++j) // 表示从主串的第i个字符开始和子串的第一个字符比较
            // 如果相等，i++，j++
            {
                if (haystack[i + j] != needle[j])
                    break; // 每次匹配失败就立刻停止当前子串的匹配，子串移动到主串下一位进行比较，也就是i+1
            }
            if (j == n) // 表示从主串的第i个字符开始和子串的第一个字符比较，并且每次匹配成功
                return i;
        }
        return -1;
    }
};
// @lc code=end
