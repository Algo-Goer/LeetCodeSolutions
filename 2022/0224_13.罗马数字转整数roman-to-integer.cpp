/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
/*
字符串题目
规则：
1、罗马数字由I,V,X,L,C,D,M这7种字符构成
2、小数字在大数字右边，则大数字加小数字，如VI=6
3、小数字在大数字左边，则大数字减小数字,如IV=4
*/

class Solution
{
private:
    unordered_map<char, int> romanValues =
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

public:
    int romanToInt(string s)
    {
        int res = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            int cur = romanValues[s[i]];
            if (i < len - 1 && cur < romanValues[s[i + 1]])  // 因为后续有s[i+1]，防止越界，这个条件不可少
               res -= cur;
            else 
                res += cur;
        }
        return res;
    }
};
// @lc code=end
