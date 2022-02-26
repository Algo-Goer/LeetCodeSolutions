/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
/*
模拟4种情况
1）R...R -> RRRRRRR
2) L...L -> LLLLLL
3) L...R -> L...R
4) R...L -> RRRLLL or RRR.LLL 中间骨牌个数偶数则对半分；奇数则则中间骨牌为'.'，其余对半分
*/
class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        // 在最左边和最右边加两张虚拟骨牌，分别是L和R，不影响骨牌最后状态
        dominoes = 'L' + dominoes + 'R';
        int n = dominoes.size();
        int left = 0;
        string ans;
        for (int right = 1; right < n; ++right)
        {
            if (dominoes[right] == '.')
                continue; // 如果是'.'，则继续for循环
            // right指针遇到L或R时停下来，计算right指针和left指针中间有多少骨牌
            int num_mid_dominoes = right - left - 1;
            if (left != 0) // 虚拟的牌不放入结果
                ans += dominoes[left];
            if (dominoes[left] == dominoes[right]) // R...R或L...L，一开始是L...L
                ans += string(num_mid_dominoes, dominoes[left]); // string()构造函数，构造一个字符串，第一个参数为数量，第二个参数为需要重复的字符
            else if (dominoes[left] == 'L' && dominoes[right] == 'R')
                ans += string(num_mid_dominoes, '.');  // L...R
            else // R...L -> RRRLLL or RRR.LLL 中间骨牌个数偶数则对半分；奇数则则中间骨牌为'.'，其余对半分
                ans += string(num_mid_dominoes / 2, 'R') + (num_mid_dominoes % 2 == 1 ? "." : "") + string(num_mid_dominoes / 2, 'L');
            left = right; // 更新left指针，找下一个区间 
        }
        return ans;
    }
};
// @lc code=end

