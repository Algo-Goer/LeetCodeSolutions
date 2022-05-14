/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
// code2 类[234]回文链表，把链表分成前后两半，然后把其中一半反转
class Solution
{
public:
    // 不同于[234]反转链表的地方
    /*
    [1,2,3,4,5,6]->mid[3,4,5,6]->[4,5,6]->[6,5,4]->[1,6,2,5,3,4]
    [1,2,3,4,5]->mid[3,4,5]->[4,5]->[5,4]->[1,5,2,4,3]
    */
    void reorderList(ListNode *head)
    {
        ListNode *l1 = head;
        ListNode *mid = findCenter(head); 
        ListNode *l2 = mid->next;
        mid->next = NULL; // 将链表从中间断开 
        l2 = reverse(l2); 
        merge(l1, l2); 
    }

    // 辅助函数：[206]反转链表
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    // 辅助函数：[876]链表的中间节点 快慢指针 不需要考虑链表长度奇偶性，但跟[876]不同： [1,2,3,4,5,6]输出结果为[3,4,5,6] [1,2,3,4,5]的输出结果为[3,4,5]
    ListNode *findCenter(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next) // [876]是while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next; // 快指针一次走两步
        }
        return slow;
    }

    // 不同于[234]反转链表的地方 辅助函数：合并
    void merge(ListNode *l1, ListNode *l2)
    {
        ListNode *cur1 = NULL;
        ListNode *cur2 = NULL;
        while (l1 && l2)
        {
            cur1 = l1->next;
            cur2 = l2->next;

            l1->next = l2;
            l1 = cur1;

            l2->next = cur1;
            l2 = cur2;
        }
    }
};
// @lc code=end
