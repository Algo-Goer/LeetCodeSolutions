--
-- @lc app=leetcode.cn id=183 lang=mysql
--
-- [183] 从不订购的客户
--

-- @lc code=start
# Write your MySQL query statement below
SELECT Customers.name as 'Customers' FROM Customers WHERE Customers.id NOT IN (SELECT CustomerId FROM Orders)
-- @lc code=end

