/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
/*
题目要求在O(1)时间内检索到最小元素
题目要求设计一个支持各类栈操作的栈

新建两个栈，一个用来存储元素，一个用来存储元素的最小值
第一个栈其实是最小栈的辅助栈

栈的插入、删除、返回栈顶元素时间复杂度都是O(1)
最坏情况下，连续插入n个元素，都还没遇到最小值，所以空间复杂度为O(n)
*/

class MinStack
{
    stack<int> s;
    stack<int> min_stack;

public:
    MinStack()
    {
        min_stack.push(INT_MAX); // 用INT_MAX初始化最小栈
    }

    void push(int val)
    {
        s.push(val);
        min_stack.push(min(min_stack.top(), val)); // 将最小栈的栈顶元素与当前元素比较，取较小的那个
    }

    void pop()
    {
        s.pop();
        min_stack.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
