--
-- @lc app=leetcode.cn id=1873 lang=mysql
--
-- [1873] 计算特殊奖金
--

-- @lc code=start
# Write your MySQL query statement below
SELECT employee_id, CASE WHEN mod(employee_id, 2) = 1 AND name NOT LIKE 'M%' THEN salary ELSE 0 END AS bonus
FROM employees ORDER BY employee_id
-- @lc code=end

