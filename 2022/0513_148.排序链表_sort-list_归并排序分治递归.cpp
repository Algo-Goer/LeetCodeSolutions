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
// code1 自上向下归并排序&分治&递归 时间复杂度O(nlogn) 空间复杂度O(logn)
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *mid = findCenter(head); // [1,2,3,4,5,6] [3,4,5,6]
        ListNode *l1 = head;
        ListNode *l2 = mid->next; // [4,5,6]
        mid->next = NULL;         // [1,2,3] [4,5,6]
        l1 = sortList(l1);        // 递归排序左子链表
        l2 = sortList(l2);        // 递归排序右子链表
        return merge(l1, l2);     // 合并两个有序子链表
    }

    // 辅助函数[876]链表的中间节点
    ListNode *findCenter(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
