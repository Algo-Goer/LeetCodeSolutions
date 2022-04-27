/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
// code3 单指针法
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int n = 0;
        ListNode *p = head;
        while (p)
        {
            ++n;
            p = p->next;
        }
        int k = 0;
        p = head;
        while (k < n / 2)
        {
            ++k;
            p = p->next;
        }
        return p;
    }
};
// @lc code=end
