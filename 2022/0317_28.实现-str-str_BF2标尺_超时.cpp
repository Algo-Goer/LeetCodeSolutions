/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
/*
主串位置i
模式串位置j
k为与模式串比对的标尺在主串中的位置
*/
/*
思路就是如果字母相同，就把尺子和单词都往前再进一位，比对下一个字母，k+=1，j+=1
*/
/*
双重循环，每一次都是一步步加1进行比对，所以性能为O(n*m)
*/

// 案例全过，但超时
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int i, j, k = 0;
        int found = 0;
        int m = haystack.size();
        int n = needle.size();
        if (n == 0)
            return 0;
        /*
        if (n == 0 || m == 0)
            return 0;
        WA:
        Testcase: "" "a"
        Answer:0
        Expected Answer:-1
        */

        // 双重循环
        for (i = 0; i < m; ++i)
        {
            j = 0;
            k = i;                                             // 尺子开始位置为i，对准主串当前位置；如果没有匹配，那么进入下一个循环，i++，k=i，所以k也k++
            while (k < m && j < n && haystack[k] == needle[j]) // 匹配的话k和j继续往前移动，i不要动
            {
                k++;
                j++;
                if (k > m || j >= n)
                    break; // 如果尺子超出主串边界，或者j超出模式串边界，就跳出循环
            }
            if (j >= n)
            {
                found = 1; // 如果j等于模式串长度，就说明找到了
                break;
            }
        }
        if (found == 1)
            return i;
        else
            return -1;
    }
};
// @lc code=end
