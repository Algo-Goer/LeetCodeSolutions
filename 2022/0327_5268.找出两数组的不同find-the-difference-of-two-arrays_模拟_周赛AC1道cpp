/*
给你两个下标从0开始的整数数组nums1和nums2
请你返回一个长度为2的列表answer
其中：
answer[0]是nums1中所有不存在于nums2中的不同整数组成的列表
answer[1]是nums2中所有不存在于nums1中的不同整数组成的列表

注意：列表中的整数可以按任意顺序返回
*/
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s1, s2;
        for (auto i : nums1)
            s1.insert(i);
        for (auto i : nums2)
            s2.insert(i);
        vector<int> ans1, ans2;
        for (auto i : s1)
            if (s2.find(i) == s2.end())
                ans1.push_back(i);
        for (auto i : s2)
            if (s1.find(i) == s1.end())
                ans2.push_back(i);
        return vector<vector<int>>{ans1, ans2};
    }
};