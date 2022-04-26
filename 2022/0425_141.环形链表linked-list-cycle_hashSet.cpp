/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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

// 面试高频考题 判断环形链表
// code1 HashSet
/*
创建一个以节点ID为key的HashSet集合，用来存储遍历过的节点
每遍历一个新节点，都用新节点和HashSet集合中存储的节点进行比较，如果发现HashSet中存在与之相同的节点ID
则说明有环
如果不存在，就把这个新节点ID存入HashSet中
*/
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> visited;
        while (head)
        {
            if (visited.count(head))
                return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end
