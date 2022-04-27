/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
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
// code1 链表->数组
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        vector<ListNode *> A{head};
        while (head->next) // 一直走到链表末尾不再进入while循环
        {
            head = head->next;
            A.push_back(head);
        } // 将链表转换为数组
        int ans = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            ans += A[i]->val * pow(2, A.size() - i - 1); // 将数组中的每个元素乘以2的n次方
        }
        return ans;
    }
};
// @lc code=end
