/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 */

/**
 * 给你一个m*n的矩阵
 * 矩阵中的数字各不相同
 * 请你按任意顺序返回矩阵中的所有幸运数
 * 幸运数是指矩阵中满足同时下列两个条件的元素:
 * 在同一行的所有元素中最小
 * 在同一列的所有元素中最大
 */

// @lc code=start
/**
 * 思路:
 * 每行最小值数组min_row,每列最大值数组max_col
 * min_row[i]表示第i行的最小值,max_col[j]表示第j列的最大值
 * 遍历矩阵,如果min_row[i] == max_col[j] == nums[i][j]
 * 那nums[i][j]就是幸运数
 * 
 */
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> min_row(m, INT_MAX);
        vector<int> max_col(n, INT_MIN);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                min_row[i] = min(min_row[i], matrix[i][j]);
                max_col[j] = max(max_col[j], matrix[i][j]);
            }
        }
        vector<int> res;  // result
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (min_row[i] == max_col[j] && min_row[i] == matrix[i][j])
                {
                    res.push_back(min_row[i]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
/**
 * push_back()函数的用法
 * 在Vector最后添加一个元素（参数为要插入的值）
 * 
 * 在vec尾部添加10
 * vector<int> vec;
 * vec.push_back(10);
 * 
 * 在容器中添加10
 * int num = 10;
 * vector<int> vec;
 * vec.push_back(num);
 * 
 * 在string中最后插入一个字符；
 * string str;
 * str.push_back('d');
 * 
 * pop_back() //移除最后一个元素
 * clear()  //清空所有元素
 * empty() //判断vector是否为空，如果返回true为空
 * erase() // 删除指定元素
 */
