/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
/*
栈
*/
class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> s;
        int res = 0;
        for (auto &op : ops)
        {
            if (op == "C")
            {
                s.pop();
            }
            else if (op == "D")
            {
                s.push(s.top() * 2); // stack::push();//在栈顶增加元素
                // 区别：vector::void push_back (const value_type& val);
            }
            else if (op == "+")
            {
                // 栈顶加入目前s中倒数两个元素之和
                int tmp = s.top(); // top()返回栈顶元素，pop()移除栈顶元素
                s.pop();
                int newtop = tmp + s.top(); // peek()为什么无法使用，peek()返回栈顶元素但不移除栈顶元素
                s.push(tmp);
                s.push(newtop);
            }
            else // 数字
            {
                s.push(stoi(op)); // 别忘记"5"->5，这是char->int的转换
            }
        }
        while (!s.empty())
        {
            res += s.top();
            s.pop();
        }
        return res;
    }
};
// @lc code=end
