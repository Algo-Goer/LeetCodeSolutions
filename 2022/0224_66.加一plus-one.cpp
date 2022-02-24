/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

/*
一开始用用的是字符转数字，数字再转字符，再拆分的方法，用了stoi(),-'0'等方法，但是stoi()超时了
所以用其他方法
或许等写代码基础更扎实的时候，也会用上面方法再写一遍
*/

/*
因为+1是从数字末尾开始，所以从右往左遍历
如果末尾没有9，则末尾直接加1，例如[1,2,3]->[1,2,4]
如果末尾有若干9，则找出从末尾开始的第一个不是9的元素并加1，例如[1,2,3,9,9]->[1,2,4,0,0]，然后将末尾9全部置零
如果末尾全是9，例如[9,9,9]->[1,0,0,0]，则建立长度比digits多1的新数组，将首元素置1，其余元素置0
*/

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        // 最后一位如果不是9，直接加1并返回结果
        if (digits[n - 1] != 9)
        {
            digits[n - 1]++;
            return digits;
        }

        // 找出从末尾开始的第一个不是9的元素并加1，例如[1,2,3,9,9]->[1,2,4,0,0]，然后将末尾9全部置零
        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                for (int j = i + 1; j < n; ++j)
                {
                    digits[j] = 0;
                }
                return digits;
            }
        }

        // 都是9，新建数组，将首元素置1，其余元素置0，长度为n+1
        vector<int> res(n + 1, 0);
        res[0] = 1;
        return res;
    }
};
    // @lc code=end
