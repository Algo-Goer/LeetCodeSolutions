/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
/*
说明：不支持栈，可以用list或deque（双端队列）来模拟一个栈，只要是标准栈操作即可
这里用双栈，将一个栈当作输入栈，用于压入传入的数据；
另一个栈当作输出栈，用于pop和peek操作
每次pop或peek时，若输出栈空则将输入栈的全部数据依次弹出并压入输出栈，
这样输出栈从栈顶往栈底的顺序就是队列从队首往队尾的顺序
*/
class MyQueue
{
    // 自定义
private:
    stack<int> inStack, outStack;

    void inToOut()
    {
        while (!inStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        inStack.push(x);
    }

    int pop()
    {
        if (outStack.empty())
            inToOut();
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    int peek()
    {
        if (outStack.empty())
        {
            if (inStack.empty()) // 因为有empty()方法，所以不写也可
                return -1;       // 题目中若队列中没有元素，则deleteHead操作返回-1
            inToOut();
        }
        return outStack.top();
    }

    bool empty()
    {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
