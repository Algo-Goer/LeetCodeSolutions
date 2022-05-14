/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
// code1 新建数组 类似[234]回文链表
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == NULL) return;
        vector<ListNode *> arr;
        ListNode *cur = head;
        while (cur)
        {
            arr.push_back(cur);
            cur = cur->next; 
        }
        int i = 0, j = arr.size() - 1;
        while (i < j) // 比[234]回文链表直接更复杂一点，所以是Medium
        {
            arr[i]->next = arr[j];
            ++i;
            if (i == j) break; 
            arr[j]->next = arr[i];
            --j;
        }
        // 勿忘最后一个元素
        arr[i]->next = NULL;
    }
};
// @lc code=end
