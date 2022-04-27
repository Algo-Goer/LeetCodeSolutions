/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
// code1 分三段&反转&拼接
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *p = dummy; // 用来遍历的指针
        // 先断开4和5，再断开1和2
        for (int i = 0; i < right; ++i)
        {
            p = p->next;
        }

        ListNode *c = p->next;
        p->next = NULL; // 断开

        p = dummy;
        for (int i = 0; i < left - 1; ++i)
        {
            p = p->next;
        }
        ListNode *b = p->next;
        p->next = NULL; // 断开

        // 反转链表
        b = reverseLinkedList(b);

        p = dummy;
        while (p->next)
            p = p->next;
        p->next = b;
        while (p->next)
            p = p->next;
        p->next = c;

        return dummy->next;
    }
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode* last = NULL;
        ListNode* cur = head;
        ListNode* next;
        
        while (cur)
        {
            next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        return last;
    }
};
// @lc code=end
