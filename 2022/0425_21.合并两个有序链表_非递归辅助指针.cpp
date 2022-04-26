/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
// code2 非递归/辅助指针

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 合并后链表的哨兵节点
        ListNode *head = new ListNode(-1);
        ListNode *pre = head;
        // 循环遍历，将两个链表中较小值插入到合并后的链表
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                pre->next = list1;
                list1 = list1->next;
            }
            else
            {
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        // 将剩余费空链表插入到合并链表后面
        if (list1)
            pre->next = list1;
        else
            pre->next = list2;
        return head->next;
    }
};
// @lc code=end
