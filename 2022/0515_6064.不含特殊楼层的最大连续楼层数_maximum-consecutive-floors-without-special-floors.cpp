/*
不含特殊楼层的最大连续楼层数

Alice管理着一家公司，并租用大楼的部分楼层作为办公空间。Alice决定将一些楼层作为特殊楼层，仅用于放松
给你两个整数bottom和top，表示Alice租用了从bottom到top（含bottom和top在内）的所有楼层
另给你一个整数数组special，其中special[i]表示 Alice指定用于放松的特殊楼层
返回不含特殊楼层的最大连续楼层数

示例 1：
输入：bottom = 2, top = 9, special = [4,6]
输出：3
解释：下面列出的是不含特殊楼层的连续楼层范围：
- (2, 3) ，楼层数为 2 。
- (5, 5) ，楼层数为 1 。
- (7, 9) ，楼层数为 3 。
因此，返回最大连续楼层数 3

示例 2：
输入：bottom = 6, top = 8, special = [7,6,8]
输出：0
解释：每层楼都被规划为特殊楼层，所以返回 0


提示
special中的所有值互不相同
*/

class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        special.push_back(bottom - 1);
        special.push_back(top + 1); // 为了方便处理最上面和最下面的区域，加上之后不影响，最上面最下面都是0
        sort(special.begin(), special.end());
        int n = special.size();
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            res = max(res, special[i] - special[i - 1] - 1);
        }
        return res;
    }
};