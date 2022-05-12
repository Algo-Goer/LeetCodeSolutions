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
// code1 快慢指针
/*
比方法二性能更好。只需遍历一次即可
1. 定义两个指针fast和slow
2. 添加一个哑节点作为链表头节点，并让两个指针都指向头节点
3. 让fast从头节点起向后移动n+1个节点，使得fast指向的节点与slow指向的节点之间间隔n个节点
4. 遍历链表，让fast和slow向后移动并始终保持两者之间间隔n个节点，直到fast指向末尾的NULL
5. 将slow指向的节点的next指针设置为指向下下个节点
*/
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head; // 不可少，否则出现runtime error:member access within null pointer of type 'ListNode'
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        for (int i = 0; i <= n; ++i) // 快指针先走n+1步，取等号，两者之间相隔n个节点
        {
            fast = fast->next;
        }
        // 两指针一起走，每次走一步，直至fast指向指向NULL
        while (fast)
        {
            fast = fast->next; // 当fast为链表尾部时非空，最后一次进入while循环，再往后移动一位，指向NULL，相当于5后的NULL
            slow = slow->next; // 3，和fast中间隔了2个节点
        }
        // 此时slow->next即要删除的节点，也就是3->next
        slow->next = slow->next->next;
        return dummy->next;
    }
};
// @lc code=end
