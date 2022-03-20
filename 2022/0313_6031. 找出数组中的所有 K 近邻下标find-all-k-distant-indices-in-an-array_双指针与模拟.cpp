/*
给你一个下标从0开始的整数数组nums和两个整数key和k
K近邻下标是nums中的一个下标i并满足至少存在一个下标j使得|i - j| <= k且nums[j] == key
以列表形式返回按递增顺序排序的所有K近邻下标
*/

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> res;
        vector<int> tmp; // key的下标
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            if (nums[left] == key)
            {
                tmp.push_back(left);
                left++;
            }
            else if (nums[right] == key)
            {
                tmp.push_back(right);
                right--;
            }
            else
            {
                left++;
                right--;
            }
        }
        // 对nums中的每个下标i遍历,j为tmp中的元素,如果|i - j| <= k,就将i加入到res中
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < tmp.size(); ++j)
            {
                if (abs(i - tmp[j]) <= k)
                {
                    res.push_back(i);
                    break;    // 跳出最内部的for循环,i++                              
                    /*
                    没有break会出现WA,i不变j++
                    输入：[2,2,2,2,2]
                    2 
                    (tmp = [0, 1, 2, 3, 4])
                    输出：[0,0,0,1,1,1,1,2,2,2,2,2,3,3,3,3,4,4,4]
                    预期结果：
                    [0,1,2,3,4]
                    */
                }
            }
        }
        return res;
    }
};