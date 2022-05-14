/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
// code2 Recursive
/*
方法二：快慢指针
1. 找到前半部分链表的尾节点：计算链表节点数，然后遍历链表找到前半部分的尾节点。也可以用快慢指针，慢指针一次走一步，快指针一次走两步，
快慢指针同时出发。当快指针移动到链表末尾时，慢指针恰好到链表中间。慢指针将链表分为两部分。若链表有奇数个节点，则中间的节点应该看作是前半部分
2. 反转后半部分链表：使用[206]反转链表
3. 判断是否回文：比较两部分值，当后半部分到达末尾则比较完成
4. 恢复链表：与2同，再一次反转即可
5. 返回结果
*/
/*
reverse linked list
ListNode *reverseList(ListNode *head)
{
    ListNode *cur = head;
    ListNode *pre = NULL;
    while (cur)
    {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
*/
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // 反转slow指针（指向中点）链表 
        ListNode *right = reverse(findCenter(head));
        ListNode *left = head;
        // 比较左半部分和反转后的右半部分是否相等，不需要考虑链表长度奇数偶数
        while (right)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    // 反转链表辅助函数 [206]反转链表
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    // 采用快慢指针确定中间位置辅助函数 [876]链表的中间节点 不需要考虑链表长度奇数偶数
    ListNode *findCenter(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next) 
        {
            slow = slow->next;       // 慢指针一次走一步
            fast = fast->next->next; // 快指针一次走两步
        }
        return slow;
    }
};
// @lc code=end
