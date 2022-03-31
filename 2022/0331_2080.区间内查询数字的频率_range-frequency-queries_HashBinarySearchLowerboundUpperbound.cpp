/*
 * @lc app=leetcode.cn id=2080 lang=cpp
 *
 * [2080] 区间内查询数字的频率
 */

// @lc code=start
// 设计数据结构
// 哈希+二分查找
class RangeFreqQuery
{
private:
    // 数值为key，位置下标为value
    unordered_map<int, vector<int>> freq;

public:
    RangeFreqQuery(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; ++i)
        {
            freq[arr[i]].push_back(i); // 将数值出现的下标存入freq中，一定是升序的
        }
    }

    int query(int left, int right, int value)
    {
        // 二分查找区间范围[left, right]
        auto l = lower_bound(freq[value].begin(), freq[value].end(), left);
        // C++11 auto关键字可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型,类似的关键字还有decltype
        auto r = upper_bound(freq[value].begin(), freq[value].end(), right);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end
