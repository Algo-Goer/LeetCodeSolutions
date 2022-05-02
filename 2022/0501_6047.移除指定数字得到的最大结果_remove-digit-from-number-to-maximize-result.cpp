/*
移除指定数字得到的最大结果
从number中恰好移除一个等于digit的字符后，找出并返回按十进制表示最大的结果字符串
*/
class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        int n = number.size();
        vector<string> a;
        for (int i = 0; i < n; ++i)
        {
            if (number[i] == digit)
            {
                string cur = number.substr(0, i) + number.substr(i + 1, n - (i + 1));
                a.push_back(cur);
            }
        }
        sort(a.begin(), a.end());
        string res = a.back();
        return res;
    }
};
