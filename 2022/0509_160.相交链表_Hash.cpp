/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// code1 HashSet 空间复杂度O(m)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> set;
        ListNode *cur = headA;
        while (cur)
        {
            set.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        while (cur)
        {
            if (set.find(cur) != set.end())
            {
                return cur;
            }
            cur = cur->next;
        }
        return NULL;
    }
};
// @lc code=end
