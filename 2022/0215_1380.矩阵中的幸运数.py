#
# @lc app=leetcode.cn id=1380 lang=python3
#
# [1380] 矩阵中的幸运数
#
'''
给你一个m*n的矩阵
矩阵中的数字各不相同
请你按任意顺序返回矩阵中的所有幸运数
幸运数是指矩阵中满足同时下列两个条件的元素:
在同一行的所有元素中最小
在同一列的所有元素中最大
'''

'''
思路:
1、每行最小值数组min_row,每列最大值数组max_col
2、min_row[i]表示第i行的最小值,max_col[j]表示第j列的最大值
3、遍历矩阵,如果min_row[i] == max_col[j] == nums[i][j],那nums[i][j]就是幸运数
'''
# @lc code=start
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        min_row = [min(row) for row in matrix]
        max_col = [max(col) for col in zip(*matrix)]  # zip(*matrix)二维矩阵变换
        ans = []
        for i, row in enumerate(matrix):
            for j, num in enumerate(row):
                if min_row[i] == max_col[j] == num:
                    ans.append(num)
        return ans
          


# @lc code=end

'''
二维矩阵变换
>>> matrix =  [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
>>> map(list,zip(*matrix))
[[1, 4, 7], [2, 5, 8], [3, 6, 9]]
1
2
3
这里来解释一下zip*通常用来解压
这里zip(*matrix)产生了行列互换的元组
再用map方法转换成list
'''

'''
python中的enumerate()函数用于遍历序列中的元素以及它们的下标

data = []
    data.append(('预约码', '车牌号码', '进校时间段', '出校时间段', '进校校区',))
    for i in car_orders:
        data.append((i.order_number, i.car_number, i.during_in_time, i.during_out_time, i.in_school))

    for i, row in enumerate(data):
        for j, col in enumerate(row):
            booksheet.write(i, j, col)
'''