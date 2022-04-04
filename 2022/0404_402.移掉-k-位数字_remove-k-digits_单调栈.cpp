/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
/*
贪心&单调栈
要让剩下数字最小，就要保证靠前的数字尽可能小（贪心）
比如425，要删去4，也就是说看到从左到右有递减的序列，就要删掉左边的大数字
如果没有这样的序列，比如是245，那就删除最后一个数字

基于此，可以每次删去一个字符后，剩下的n-1个长度的序列就形成新的子问题，继续用同样方法，直至删k次

可以用单调非严格递增栈-找寻下一个更小的数字
对于每个数字，如果该数字小于栈顶元素，就不断弹出栈顶元素，直到
1. 空栈
2. 或新的栈顶元素不大于当前数字
3. 或已经删除k次
*/
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string st;
        for (char c : num)
        {
            while (k > 0 && !st.empty() & c < st.back())
            {
                st.pop_back();
                k--;
            }
            if (st.empty() && c == '0')
                continue; // 除了0之外都没有前导0，例如10200删除1之后就是200
            st.push_back(c);
        }
        while (!st.empty() && k > 0)
        {
            st.pop_back(); 
            k--;
        }
        return st == "" ? "0" : st; // 如果st为空，返回"0"
    }
};
/*
举例1
num="1432219", k=3
c='1', st="", k=3,  st="1"
c='4', st="14"
c='3', 3<4, st="1", k=2, st="13"
c='2', 2<3, st="1", k=1, st="12"
c='2', st="122"
c='1', 1<2, st="12", k=0, st="121"
c='9', k=0不进入while循环, st="1219"
st="1219"

举例2
num="10200", k=1
c='1', st="", k=1, st="1"
c='0', 0<1, st="", k=0, continue,'0'不压入st, 进入下一个for循环
c='2', k=0不进入while循环, st="2"
c='0', k=0不进入while循环, st="20"
c='0', k=0不进入while循环, st="200"
st="200"

举例3
num="10", k=2
c='1', st="", k=2, st="1"
c='0', 0<1, st="", k=1, st="0"
满足st非空且k>0, st="", k=0
st="0"
*/
// @lc code=end
