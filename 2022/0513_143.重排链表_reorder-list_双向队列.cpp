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
// code3 双向队列 学习@代码随想录
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        deque<ListNode *> dq;
        ListNode *cur = head;
        if (cur == NULL)
            return;

        while (cur->next)
        {
            dq.push_back(cur->next);
            cur = cur->next;
        }

        cur = head;
        int count = 0; // 计数，偶数取后面，奇数取前面
        ListNode *node;
        while (dq.size())
        {
            if (count % 2 == 0)
            {
                node = dq.back(); 
                dq.pop_back(); 
            }
            else
            {
                node = dq.front();
                dq.pop_front();
            }  
            count++;
            cur->next = node;
            cur = cur->next; 
        }
        cur->next = NULL; // 注意结尾
    }
};
// @lc code=end
