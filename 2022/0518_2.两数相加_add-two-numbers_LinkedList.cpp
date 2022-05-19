/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 和的链表头节点前加dummy
        auto dummy = new ListNode(0);
        auto cur = dummy; // cur指向当前链表的尾节点
        int t = 0;   // 进位
        while (l1 || l2 || t) 
        {
            if (l1) t += l1->val, l1 = l1->next;
            if (l2) t += l2->val, l2 = l2->next;
            cur = cur->next = new ListNode(t % 10); // 创建一个数值为sum % 10的新节点，并将其设置为当前节点的下一个节点，然后将当前节点前进到下一个节点
            t /= 10;
        }
        return dummy->next;
    }
};
// @lc code=end

