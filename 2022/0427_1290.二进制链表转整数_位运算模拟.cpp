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
// code3 位运算&模拟
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int ret = 0;
        while (head)
        {
            ret <<= 1;        // 左移一位
            ret |= head->val; // 将当前节点值加入res
            head = head->next;
        }
        return ret;
    }
};
// @lc code=end
