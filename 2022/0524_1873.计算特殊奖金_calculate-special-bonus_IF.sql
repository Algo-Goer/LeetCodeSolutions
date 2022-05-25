--
-- @lc app=leetcode.cn id=1873 lang=mysql
--
-- [1873] 计算特殊奖金
--

-- @lc code=start
# Write your MySQL query statement below
SELECT employee_id, IF (employee_id % 2 = 1 AND LEFT(name, 1) != 'M', salary, 0) AS bonus 
FROM employees  
# SELECT employee_id,中的','不可以省略
-- @lc code=end

