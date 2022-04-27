/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
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

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        ListNode *next = node->next;
        node->next = node->next->next;
        delete next;
    }
};
// @lc code=end

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        // 特殊情况：删除的节点是头节点
        if (head->val == val)
            return head->next;
        // two pointers
        ListNode *prev = head;
        ListNode *cur = head->next;
        // 当cur为空或cur值==val，跳出循环
        while (cur && cur->val != val)
        {
            // 两个指针不断向前移动
            // pre来到cur位置
            pre = cur;
            cur = cur->next
        }
        // 相当于覆盖了cur的节点值
        pre->next = cur->next;
        // 最后返回链表头节点即可
        return head;
    }
};