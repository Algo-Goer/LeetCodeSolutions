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
// code4 stack
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode *p = head;
        // 把链表中的节点入栈
        while (p)
        {
            st.push(p);
            p = p->next;
        }
        // 判断若栈为空，则返回NULL
        if (st.empty())
            return NULL;
        // 从栈中取出元素，然后组成链表，则为反转后的链表
        ListNode *newHead = st.top();
        st.pop();
        ListNode *pNew = newHead;
        while (!st.empty())
        {
            pNew->next = st.top();
            st.pop();
            pNew = pNew->next;
        }
        // 最后一个节点的next置为空，否则会构成环
        pNew->next = NULL;
        return newHead;
    }
};
// @lc code=end
