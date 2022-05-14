/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// code1 新建数组
/*
方法一：新建数组
1. 复制链表值到新建数组中
2. 使用双指针判断是否回文
*/
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> arr;
        while (head)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = (int)arr.size() - 1; i < j; ++i, --j)
        {
            if (arr[i] != arr[j])
                return false;
        }
        return true;
    }
};
// @lc code=end
