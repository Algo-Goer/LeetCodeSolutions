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
// code2 辅助三指针/迭代
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pReversedHead = NULL;
        ListNode *pNode = head;
        ListNode *pPrev = NULL;
        while (pNode)
        {
            ListNode *pNext = pNode->next;
            if (pNext == NULL) // 到达链表尾节点
                pReversedHead = pNode;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReversedHead;
    }
};
// @lc code=end
