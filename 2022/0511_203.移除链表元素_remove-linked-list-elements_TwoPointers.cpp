/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
/*
链表删除节点题:
面试题02.03.删除中间节点
237.删除中间节点
剑指Offer18.删除链表的节点
876.链表的中间节点
区别在于本题可能删除多个节点，有重复值
*/

// Two Pointers
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(0); // 添加虚拟节点可以避免对头节点的判断
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *cur = head;
        while (cur)
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
            }
            else
            {
                prev = prev->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end
