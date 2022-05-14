/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
// code2 自下向上归并排序&分治 时间复杂度O(nlogn) 空间复杂度O(1)
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        int length = 0;
        ListNode *cur = head;
        while (cur)
        {
            ++length;
            cur = cur->next;
        }
        ListNode *dummy = new ListNode(0, head); 
        for (int subLength = 1; subLength < length; subLength <<= 1) // <<= 1表示每次长度翻倍
        {
            ListNode *pre = dummy, *cur = dummy->next;
            while (cur)
            {
                ListNode *head1 = cur;
                for (int i = 1; i < subLength && cur->next; ++i)
                {
                    cur = cur->next;
                }
                ListNode *head2 = cur->next;
                cur->next = NULL;
                cur = head2;
                for (int i = 1; i < subLength && cur && cur->next; ++i)
                {
                    cur = cur->next;
                }
                ListNode *next = NULL;
                if (cur)
                {
                    next = cur->next;
                    cur->next = NULL;
                }
                ListNode *merged = merge(head1, head2);
                pre->next = merged;
                while (pre->next)
                {
                    pre = pre->next;
                }
                cur = next;
            }
        }
        return dummy->next;
    }

    // 辅助函数[21]合并两个有序链表
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0); // 合并链表的哑结点
        ListNode *cur = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        // 将剩余非空链表插入到合并链表
        if (l1)
            cur->next = l1;
        if (l2)
            cur->next = l2;
        return dummy->next;
    }
};
// @lc code=end
