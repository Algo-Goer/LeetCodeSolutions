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

// code2 空间复杂度O(1)，学习了吴师兄学算法的代码
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 边界判断
        if (!headA || !headB) return NULL; // 如果两个链表有一个为空，则相交点为空
        // 定义两个指针，分别指向两个链表头节点
        ListNode *p = headA;
        ListNode *q = headB;
        // 指针p和q不断向后遍历，直到找到相交点
        while (p != q)
        {
            // 指针p一开始在链表A上遍历，当走到链表A的尾部即NULL时，跳转到链表B上
            p = p == NULL ? headB : p->next;
            // 指针q一开始在链表B上遍历，当走到链表B的尾部即NULL时，跳转到链表A上
            q = q == NULL ? headA : q->next;
        }
        // 返回相交点
        return p;
    }
};
// @lc code=end
