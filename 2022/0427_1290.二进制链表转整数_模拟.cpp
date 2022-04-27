/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
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
// code2 模拟
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        ListNode *p = head;
        int ans = 0;
        while (p)
        {
            ans = ans * 2 + p->val;
            p = p->next;
        }
        return ans;
    }
};
// @lc code=end
