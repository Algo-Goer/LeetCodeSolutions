/*
给你一个下标从0开始的整数数组nums
如果满足下述条件
则认为数组nums是一个美丽数组：
nums.length为偶数
对所有满足i%2==0的下标i
nums[i]!=nums[i + 1]均成立

注意，空数组同样认为是美丽数组
你可以从nums中删除任意数量的元素
当你删除一个元素时，被删除元素右侧的所有元素将会向左移动一个单位以填补空缺，而左侧的元素将会保持不变

返回使nums变为美丽数组所需删除的最少元素数目
*/

/*
为什么可以想到栈呢：
在原数组之外需要新建一个数组，这个数组能删除相邻的元素，就可以考虑栈顶和当前元素的关系
*/

class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        stack<int> s;
        int res = 0;
        for (auto& num : nums)
        {
            if (!s.empty() && s.size()&1 && s.top() == num) // 如果非空栈且奇数个数栈顶元素等于当前元素
            // s.size()&1表示s.size()是奇数
                res++; // 1
            else   // 如果栈中元素个数是偶数个数或空栈，就直接放入新元素
                s.push(num); // 1,2,2,3,3
            
        }
        if (s.size()&1) // 1,2,2,3,3下标为4的元素3后面没有元素，还是得删除，所以res+1
            res++; 
        return res;
    }
};