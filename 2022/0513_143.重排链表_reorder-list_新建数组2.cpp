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
// code4 新建数组 写法二
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;
        vector<ListNode *> arr;
        ListNode *cur = head;
        while (cur)
        {
            arr.push_back(cur);
            cur = cur->next;
        }

        int n = arr.size();
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            arr[r]->next = arr[l]->next;
            arr[l]->next = arr[r];
            l++;
            r--;
        }
        arr[l]->next = NULL;
    }
};
// @lc code=end
