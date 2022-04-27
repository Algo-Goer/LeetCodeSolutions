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
// code2 新建数组
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        vector<ListNode *> A = {head};
        while (head->next)
        {
            head = head->next;
            A.push_back(head);
        }
        return A[A.size() / 2];
    }
};
// @lc code=end
