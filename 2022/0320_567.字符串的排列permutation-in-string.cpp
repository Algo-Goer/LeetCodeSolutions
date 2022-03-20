/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
/*
类同第438题，类异位词
设s1长度为n，可以遍历s2中的每个长度为n的子串，判断子串和s1中每个字符个数是否相等，若相等，则说明该子串是s1的一个异位词
用两个数组cnt1,和cnt2，cnt1统计s1中各个字符个数，cnt2统计当前遍历的子串中各个字符个数
可用一个固定长度为n的滑动窗口来维护cnt2：滑动窗口每向右滑动一次，就多统计一次进入窗口的字符，减去一次离开窗口的字符的个数
判断cnt1是否与cnt2相等，若相等，则意味着s1的异位词中有一个是s2的子串
*/
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s1.size();
        if (n > s2.size())
            return false;
        vector<int> cnt1(26, 0); // s1和s2仅包含小写字母
        vector<int> cnt2(26, 0);
        for (auto &ch : s1)
        {
            cnt1[ch - 'a']++;
        }
        for (auto &ch : s2.substr(0, n))
        {
            cnt2[ch - 'a']++;
        }
        if (cnt1 == cnt2)
            return true;
        for (int i = 1; i < s2.size() - n + 1; ++i)
        {
            cnt2[s2[i - 1] - 'a']--;
            cnt2[s2[i + n - 1] - 'a']++;
            if (cnt1 == cnt2)
                return true;
        }
        return false;
    }
};
// @lc code=end
