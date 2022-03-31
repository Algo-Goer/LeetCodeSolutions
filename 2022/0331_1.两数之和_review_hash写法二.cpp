/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// hashmap写法二
/*
建立哈希表，对于每一个x，先O(1)查询哈希表中是否存在target-x。如果不存在，就将x存入哈希表，否则返回x和target-x的下标
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hash.find(target - nums[i]); // 先查询哈希表中是否存在target-x
            // find()函数返回一个迭代器，如果找到，返回一个迭代器，否则返回end()
            if (it != hash.end())
            {
                return {it->second, i}; // 可以按任意顺序返回答案
            }
            hash[nums[i]] = i; // 如果不存在target-x，就将x和x下标存入哈希表
            /*
            举例
            nums=[3,2,4], target=6
            不需要担心返回[0,0]-跟之前的哈希表C++代码写法一区别
            i=0，3，6-3=3没有在哈希表中，所以hash[3]=0
            i=1，2，6-2=4也没有在哈希表中，所以hash[2]=1
            i=2，4，6-4=2在哈希表中，返回两者下标[1,2]
            */
        }
        return {}; // 如果没有找到，返回空
    }
};
// @lc code=end
