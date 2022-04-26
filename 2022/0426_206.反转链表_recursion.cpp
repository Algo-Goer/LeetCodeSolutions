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
// code3 recursion
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // 递归终止条件：head指向节点为NULL，head指向节点的下一个节点为NULL
        // 这两种情况下，反转之后的结果还是它自身
        if (head == NULL || head->next == NULL)
            return head;
        // 不断通过递归调用，直到无法递归，到最后一个节点，由于当前节点head的next节点为空，所以会直接返回head
        ListNode *cur = reverseList(head->next);
        /*
        比如原链表为1->2->3->4->5
        第一次执行下面的代码时候，head为4，head->next为5
        head->next->next就是5->next，设置5的下一个节点
        等号右侧为head，设置5的下一个节点为4
        出现两个next
        第一个next是获取head的下一个节点
        第二个next是设置当前节点的下一个节点为等号右侧的值
        */
        head->next->next = head;
        /*
        head原来的下一个节点指向自己，所以head自己本身就不能再指向原来的下一个节点
        否则无限循环
        */
        head->next = NULL;
        // 把每次反转后的结果传递给上一层
        return cur;
    }
};
// @lc code=end
