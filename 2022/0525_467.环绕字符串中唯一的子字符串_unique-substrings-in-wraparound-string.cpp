/*
 * @lc app=leetcode.cn id=467 lang=cpp
 *
 * [467] 环绕字符串中唯一的子字符串
 */

// @lc code=start
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> m(26); // 记录以26个字母作结尾的有效字符串个数（去重后）哈希表
        int curLen = 1;    // 当前连续字符串有效长度，自己单独出现，默认初始值为1
        m[p[0] - 'a'] = 1;
        for (int i = 1; i < n; ++i)
        {
            int pre = p[i - 1] - 'a';
            int cur = p[i] - 'a';
            if ((cur - pre + 26) % 26 == 1) // 循环
                curLen++;
            else
                curLen = 1;
            /*
            zaba
            最后一个a单独出现的情况已经在第一个a出现的时候计算过了
            最后一个a的答案是1，但第一个a可以有a和za两个结果
            取最大值
            */
            m[cur] = max(m[cur], curLen);
        }
        int res = 0;
        // 累加数组的值，得到所有字母作为结尾的有效字符串的和
        for (int i = 0; i < 26; ++i)
        {
            res += m[i];
        }
        return res;
    }
};
// @lc code=end

