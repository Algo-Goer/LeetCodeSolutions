class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        int n = nums.size();
        if (n % 2 != 0)
            return false;
        // 将nums分成nums/2对，每对中的数字必须相等
        // 排序
        sort(nums.begin(), nums.end());
        // 判断每对中的数字是否相等
        for (int i = 0; i < n / 2; ++i)
        {
            if (nums[2 * i] != nums[2 * i + 1])
                return false;
                }
        return true;
    }
};