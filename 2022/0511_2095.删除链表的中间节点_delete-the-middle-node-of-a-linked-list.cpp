/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 *
 * [2095] 删除链表的中间节点
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
[876]链表的中间结点，不过返回的要求不同，[876]返回slow指针指向的剩余链表，本题返回删除中间节点后的整个链表
另外输入[1]，[876]返回[1]，本题返回[]
*/
// code1 快慢指针
/*
方法一：快慢指针
设置快慢指针fast和slow，都指向head
当fast和fast->next均非空，就进入while循环，slow每次走1步，fast每次走2步
当fast走到链表尾部也即fast->next == NULL，返回slow即链表的中间节点位置
*/
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL) // 空链表或链表只有一个节点，例如[1]，那么返回[]
            return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = NULL;
        while (fast && fast->next) // fast每次要走两步
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
            // // pre在slow的前面一个节点
        }
        pre->next = pre->next->next;
        return head;
    }
};
// @lc code=end
