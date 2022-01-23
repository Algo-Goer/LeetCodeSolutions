/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start

/*
 * 今天2022.1.22是学习栈的2nd天
 * Python算法设计分析书里讲了栈的两个Python实现
 * 第一个是()匹配，第二个是()、[]、{}匹配
 * 拿这道题复习一下，依旧C、Python、C++都写一遍练语法熟悉度
 */

// 本题类同[1614]括号的最大嵌套深度

/*
栈的思维：
遇到左符号就push，遇到右符号就与栈顶元素top相匹配，不匹配返回False，否则就pop出top元素，继续循环
直到栈为空，就返回True
*/
bool isValid(char *s)
{
    int len = strlen(s);
    char stack[len + 1];
    // 或char *stack = (char*)malloc(len + 1);
    int top = 0; // top后期作为stack里的指针，所以不要为-1，否则数组越下界（-1<0)
    int flag = 1;
    // 题目说数组长度大于等于1，所以不用考虑空数组
    // 如果第一个符号就是右符号，直接返回false
    if (s[0] == ')' || s[0] == ']' || s[0] == '}' || len % 2 != 0)
    {
        return false;
    }

    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack[top] = s[i]; // 左符号入栈
            top++;
        }
        else
        {
            if (top > 0)
            {
                flag = matches(stack[top - 1], s[i]); // 前面top++了，所以要top - 1;另外要防止top-1越0下界
                if (flag == 0)
                    return false; // 符号不匹配，直接返回false
                else              // 符号匹配，top元素往前推一位
                {
                    top--; // 防止数组越下界出现Runtime Error
                }
            }
            else
                return false;
        }
    }
    if (top == 0)
        return true;
    else
        return false;
}

int matches(opens, closes)
{
    if (opens == '(' && closes == ')')
        return 1;
    else if (opens == '[' && closes == ']')
        return 1;
    else if (opens == '{' && closes == '}')
        return 1;
    else
        return 0;
}
// @lc code=end
