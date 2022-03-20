/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
/*
库函数find()
*/
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        // find()
        if (needle.empty())
            return 0;
        int pos = haystack.find(needle); // find()函数返回在haystack中和needle相等的第一个元素
        return pos;
    }
};
// @lc code=end

