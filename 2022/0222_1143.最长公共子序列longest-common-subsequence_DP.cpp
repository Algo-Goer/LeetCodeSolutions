/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
// 最长公共子序列--二维DP
/*
最优子结构、无后效性--设计好的状态--分解为子问题
动态规划
MaxLen(i,j)为状态：s1的左边i个字符形成的子串与s2左边的j个字符形成的子串的最长公共子序列的长度
(i,j从0开始算)
假定len1=strlen(s1),len2=strlen(s2),那么题目就是要求MaxLen(len1,len2)
初始条件
MaxLen(n,0)=0(n=0...len1)
MaxLen(0,n)=0(n=0...len2)
状态转移方程
递推公式
if(s1[i-1]==s2[j-1])       // s1的最左边字符是s1[0]
    MaxLen(i,j)=MaxLen(i-1,j-1)+1;
else 
    MaxLen(i,j)=Max(MaxLen(i,j-1),MaxLen(i-1,j));
创建二维数组,状态有len1*len2个,计算每个状态所需的时间if else是个常数,所以
时间复杂度O(mn),m和n是两个字串长度

1 <= text1.length, text2.length <= 1000
*/
// 递推写法

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0)); // 构建并初始化二维数组，长宽都要各自比原来长度多1，用来放初始值0
        // 边界条件
        for (int i = 0; i <= len1; ++i)
            dp[i][0] = 0;
        for (int j = 0; j <= len2; ++j)
            dp[0][j] = 0;
        // 状态转移方程
        for (int i = 1; i <= len1; ++i)
        {
            for (int j = 1; j <= len2; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                // if (text1[i] == text2[j])Wrong Answer20/44 cases
                // Testcase"abc""def" Answer 1 Expected Answer 0
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            }
        }
        return dp[len1][len2];
    }
};
// 时间复杂度O(mn),空间复杂度O(mn)
// @lc code=end

