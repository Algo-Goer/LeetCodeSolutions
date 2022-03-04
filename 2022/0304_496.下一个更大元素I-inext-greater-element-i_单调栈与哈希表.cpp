/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */+

// @lc code=start
/*
无重复值
Monotonic Stack + unordered_map
O(n)
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res(nums1.size());
        stack<int> st;
        unordered_map<int, int> m;
        for (int i = 0; i < nums2.size(); ++i)
        {
            while (!st.empty() && st.top() < nums2[i]) // 如果栈顶元素小于当前元素,则弹出栈顶元素
            {
                m[st.top()] = nums2[i];  
                st.pop();
            }
            st.push(nums2[i]); // 直接push
        }
        for (int i = 0; i < nums1.size(); ++i)
        {
            res[i] = m.count(nums1[i]) ? m[nums1[i]] : -1; // 如果存在,则返回对应的值,否则返回-1
            // count()返回元素在map中出现的次数
        }
        return res;
    }
};
// @lc code=end

