--
-- @lc app=leetcode.cn id=196 lang=mysql
--
-- [196] 删除重复的电子邮箱
--

-- @lc code=start
# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE p1.*
FROM Person p1,  #别名p1
     Person p2   #别名p2
WHERE 
     p1.Email = p2.Email AND p1.Id > p2.Id; # 自连接，选出符合相等的条件就删除p1
-- @lc code=end

