/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3)
            return res;
        sort(nums.begin(), nums.end());
        // 固定i，寻找l和r
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
                break; // 如果当前数字大于0，则三数之和一定大于0，所以跳出for循环
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // 去重，i右移一位进入下一个for循环
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[l], nums[r]}); // 不要忘记加{}
                    while (l < r && nums[l] == nums[l + 1])
                        ++l; // 去重，l右移一位
                    while (l < r && nums[r] == nums[r - 1])
                        --r; // 去重，r左移一位
                    l++;
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else if (sum > 0)
                {
                    r--;
                }
            } 
        }
        return res;
    }
};
// @lc code=end
