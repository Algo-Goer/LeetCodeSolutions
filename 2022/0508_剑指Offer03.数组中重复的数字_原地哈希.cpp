// 原地哈希 类似[645]、[442]
/*
原地哈希关键词：
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内
如果是1~n范围也是关键词
*/
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] != nums[nums[i]])
            {
                swap(nums[i], nums[nums[i]]); // 各就各位，nums[i]=i，因为本题范围是0~n-1而非1~n，所以是nums[i]=i而非nums[i]=i+1
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i)
                return nums[i];
        }
        return -1;
    }
};