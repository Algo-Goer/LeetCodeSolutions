/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
// code2 双指针
/*
利用双指针（pre指针和cur指针），cur指针遍历链表
若两指针值相等，则pre指针next指向cur指针的后一个结点，pre指针不移动
否则pre指针移动到cur指针位置
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) // 空链表直接返回
            return NULL;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur)
        {
            // 当前指针遍历链表
            if (cur->val == pre->val)
            {
                // 当前指针值与前指针值相等，则前指针的next指向当前指针的下一结点
                pre->next = cur->next;
            }
            else
            {
                pre = cur; // 前指针后移
            }
            cur = cur->next; // 当前指针后移
        }
        return head;
    }
};
// @lc code=end
