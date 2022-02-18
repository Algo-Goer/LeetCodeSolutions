#
# @lc app=leetcode.cn id=688 lang=python3
#
# [688] 骑士在棋盘上的概率
#

# @lc code=start
'''
在一个n x n的国际象棋棋盘上
一个骑士从单元格 (row, column)开始
并尝试进行 k 次移动
行和列是 从 0 开始 的
所以左上单元格是 (0,0) 
右下单元格是 (n - 1, n - 1) 
象棋骑士有8种可能的走法
每次移动在基本方向上是两个单元格,然后在正交方向上是一个单元格。
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. 
The rows and columns are 0-indexed, so the top-left cell is (0, 0), 
and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. 
Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

Each time the knight is to move, 
it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) 
and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.
'''

# 三维线性动态规划
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        dp = [[[0]*n for _ in range(n)] for _ in range(k + 1)] # 创建一个三维数组
        for step in range(k + 1):   # 第一行
            for i in range(n):      # 第一列
                for j in range(n):  # 第一个元素
                    if step == 0:   # 如果是第一行
                        dp[step][i][j] = 1   # 初始化为1
                    else:  
                        for di, dj in ((-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2)): 
                            # 表示8个方向,di和dj分别表示行和列的增量
                            ni, nj = i + di, j + dj    # ni和nj分别表示新的行和列
                            if 0 <= ni < n and 0 <= nj < n:    # 如果ni和nj在0到n-1之间
                                dp[step][i][j] += dp[step - 1][ni][nj]*(1/8)  
        return dp[k][row][column]   # 返回最后一行的最后一列的值


# @lc code=end

