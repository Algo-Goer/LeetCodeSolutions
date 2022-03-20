/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// hashmap
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i)
        {
            hash[nums[i]] = i; // 存储下标
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            // 如果complement在hash的key中，则返回nums[i]和complement的下标
            if (hash.find(complement) != hash.end() && hash[complement] != i)
            /*
            如果没有这句：&& hash[complement] != i
            Wrong Answer 54/57 cases passed (N/A) Testcase [3,2,4] 6
            Answer [0,0] Expected Answer[1,2]
            */
            {
                return {i, hash[complement]};
            }
        }
        return {};
    }
};
// @lc code=end
