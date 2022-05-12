/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
// code2 单链表&获得链表长度L
/*
需要遍历两次
1. 添加一个哑节点作为辅助，让该节点成为链表头节点，主要目的是简化一些极端情况的处理，如链表只含有一个节点，或许需要删除的是链表头节点
2. 遍历一次链表，获得链表长度L
3. 设置一个指向哑节点的指针，再次遍历链表，将该指针移动至L-n个节点位置
4. 将第L-n个节点的next指针设置为指向第L-n+2个节点
*/
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0); // 不需要判断空链表
        dummy->next = head;                // 不可少
        int L = 0;
        ListNode *p = dummy;
        while (p)
        {
            ++L;
            p = p->next;
        }
        L -= 1;
        // 设置一个指向哑节点的指针，再次遍历链表，将该指针移动至第L-n个节点的位置即3这个节点
        p = dummy;
        int k = 0;
        while (k < L - n) // 0, 1, 2
        {
            ++k;
            p = p->next; // p在3
        }
        // 将第L-n个节点的next指针设置为指向第L-n+2个节点，即3->next = 5
        p->next = p->next->next;
        return dummy->next;
    }
};
// @lc code=end
