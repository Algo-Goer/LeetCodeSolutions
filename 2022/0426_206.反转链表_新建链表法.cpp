/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// code5 新建链表法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // 定义哑结点dummy
        ListNode *dummy = NULL;
        while (head)
        {
            // 先保存下一个节点
            ListNode *next = head->next;
            // 原链表中的第一个节点指向dummy
            head->next = dummy;
            // dummy指向head，head指向下一个节点
            dummy = head;
            head = next;
        }
        return dummy;
    }
};
// @lc code=end
