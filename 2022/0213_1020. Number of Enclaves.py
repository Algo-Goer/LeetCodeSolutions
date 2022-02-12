#
# @lc app=leetcode.cn id=1020 lang=python3
#
# [1020] 飞地的数量
#

# @lc code=start
# dfs深度优先遍历
# 有两种图实现：邻接矩阵和邻接表。当图为稀疏图、顶点较多，即图结构比较大时，更适宜选择邻接表作为存储结构。当图为稠密图、顶点较少时，或者不需要记录图中边的权值时，使用邻接矩阵作为存储结构较为合适
# 从四周临边的1开始上下左右用DFS遍历，把所有相连的1都变为0，最后统计grid中1的数量
# dfs函数遍历到值为0的位置会直接返回，所以只要把经过的位置都设置为0，就可以起到不走回头路的作用

from collections import deque
from re import search


class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        def dfs(i, j):
            grid[i][j] = 0
            for x, y in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                if 0 <= x < m and 0 <= y < n and grid[x][y]:
                    dfs(x, y)
        
        m, n = len(grid), len(grid[0])          # 行列数
        for i in range(m):
            if grid[i][0] == 1: 
                dfs(i, 0)
            if grid[i][n - 1] == 1:
                dfs(i, n - 1)
        for j in range(n):
            if grid[0][j] == 1:
                dfs(0, j)
            if grid[m - 1][j] == 1:
                dfs(m - 1, j)
        
        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    ans += 1
        
        return ans
# DFS伪代码
# 对图实现DFS时，必须先检查该节点是否已访问。如果不这么做，就可能陷入无限循环
# void search(Node root)
# {
#     if (root == null) return;
#     visit(root);
#     root.visited = true;
#     for each (Node n in root.adjacent)
#     {
#         if (n.visited == False)
#         {
#             search(n);
#         }          
#     }
# }

# BFS伪代码
# BFS并非通过递归实现，而是通过队列实现
# 从节点a开始按层搜索。用到队列的迭代法往往最有效
# void search(Node root)
# {
#     Queue queue = new Queue();
#     root.marked = true;
#     queue.enqueue(root);            // 加入队尾

#     while (! queue.isEmpty())
#     {
#         Node r = queue.dequeue;     // 从队列头部删除
#         visit(r);
#         for each (Node in r.adjacent)
#         {
#             if (n.marked == false)
#             {
#                 n.marked = true;
#                 queue.enqueue(n);
#             }
#         }
#     }
# }


# @lc code=end

