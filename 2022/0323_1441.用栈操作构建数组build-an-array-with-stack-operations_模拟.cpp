/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

// @lc code=start
/*
遍历数组target，如果为自然数顺序，则"Push"
如果缺失数字，则"Push"和"Pop"
*/
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> res;
        int num = 1;
        for (int i = 0; i < target.size(); ++i) // num++或++num均可
        {
            while (target[i] != num)
            /*
            如果while写成了if
            Wrong Answer 18/49 cases passed (N/A)
            Testcase [2,3,4,5,8,9,10] 10
            Answer ["Push","Pop","Push","Push","Push","Push","Push","Pop","Push","Push","Pop","Push","Push"]
            Expected Answer ["Push","Pop","Push","Push","Push","Push","Push","Pop","Push","Pop","Push","Push","Push"]
            */     
            {
                res.push_back("Push");
                res.push_back("Pop");
                num++;
            }
            res.push_back("Push");
            num++;   // 如果for循环里没有写num++，那么这里也可以写
            // 总之无论target里有没有num，num都要不断加1
        }
        return res;
    }
};
// @lc code=end
