/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
/*
昨天做的贪心方法时间复杂度O(n^2)
今天写个O(n)的贪心题解-用hashmap
*/
class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        unordered_map<int, int> map;    
        for (int i = 0; i < row.size(); ++i)
        {
            map[row[i]] = i;
        }
        int ans = 0;
        for (int i = 1; i < row.size(); i += 2)  // +2表示默认情侣都可以牵手
        {
            int target = row[i - 1] + (row[i - 1] % 2 == 0 ? 1 : -1);
            /*
            row[i - 1] % 2 == 0 ? 1 : -1表示坐在第i - 1个座位上的人的ID是否是偶数：
            如果是偶数，那么索引i上对应的数字row[i]正确数字target应为row[i - 1] + 1-例如，row=[3,2,0,1]情侣都可以牵手，偶数0右边的数字+1为1
            如果是奇数，那么索引i上对应的数字row[i]正确数字target应为row[i - 1] - 1-例如，row=[3,2,0,1]情侣都可以牵手，偶数3右边的数字-1为2
            */
            if (row[i] != target) // 如果座位ID不正确
            {
                int swapIdx = map[target];  // 从map取出正确座位ID对应的索引
                swap(row[i], row[swapIdx]); // swap()时间复杂度O(1)，空间复杂度O(1) 
                // 交换row[i]和row[swapIdx]的值，坐到正确座位上
                map[row[swapIdx]] = swapIdx; // 更新map中的值和索引
                ans++; // 交换次数加1
            }
        }
        return ans;
    }
};
// @lc code=end
