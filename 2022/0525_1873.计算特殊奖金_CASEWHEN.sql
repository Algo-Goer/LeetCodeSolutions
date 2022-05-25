--
-- @lc app=leetcode.cn id=1873 lang=mysql
--
-- [1873] 计算特殊奖金
--

-- @lc code=start
# Write your MySQL query statement below
SELECT employee_id, CASE WHEN employee_id % 2 = 1 AND LEFT(name, 1) != 'M' THEN salary ELSE 0 END bonus
FROM employees
-- @lc code=end

