/*
给你一个整数数组queries和一个正整数intLength
请你返回一个数组answer
其中answer[i]是长度为intLength的正回文数中第queries[i]小的数字
如果不存在这样的回文数，则为-1

回文数指的是从前往后和从后往前读一模一样的数字
回文数不能有前导0
*/
/*
intLength=1，回文数：1,2,3...
intLength=2，回文数：11,22,33,44...第一个数是1,2,3,4...
intLength=3，回文数：101,111,121,131,141...前两个数是10,11,12,13,14...
intLength=4，回文数：1001,1111,1221,1331,1441...前两个数是10,11,12,13,14...
intLength=5，回文数：10001,10101,10201...前三个数是100,101,102...
分奇数偶数长度进行讨论
对前一半进行分析，后一半拼接

类同LeetCode_564_寻找最近的回文数 Hard
*/
class Solution
{
public:
    vector<long long> kthPalindrome(vector<int> &queries, int intLength)
    {
        vector<long long> res;
        int len = (intLength + 1) / 2; // 构造的前一半长度，例如intLength=3，那么len=2
        int begin = 1; // 回文数开始的数字
        for (int i = 1; i < len; ++i) 
        {
            begin *= 10;  // begin = 10，后面依次是11,12,13...
        }
        for (int i = 0; i < queries.size(); ++i)
        {
            int cur = begin + queries[i] - 1; // 例如queries=[1,2,3...90],cur=10,11,12...99
            string tmp = to_string(cur); // 整数转换为字符串
            if (tmp.size() > len)  // 例如queries数组里有数字91，那就超过len长度了，不存在这样的回文数
                res.push_back(-1);
            else  // 可以构造queries对应的所有前半回文串
            {
                string total = tmp;  // 整个字符串为total，先把前一半tmp放上去
                if (intLength % 2 == 1)  // 如果intLength要求是奇数长度，那去掉最后一位数字
                {
                    tmp = tmp.substr(0, tmp.size() - 1); // 返回从0开始长度为tmp.size()-1的字符串
                }
                reverse(tmp.begin(), tmp.end());
                total += tmp;
                res.push_back(stoll(total)); // 字符串转换回整数
            }
        }
        return res;
    }
};