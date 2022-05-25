--
-- @lc app=leetcode.cn id=1667 lang=mysql
--
-- [1667] 修复表中的名字
--

-- @lc code=start
# Write your MySQL query statement below
select 
    user_id, concat (upper(left(name, 1)), lower(substring(name, 2))) name
from 
    users
order by 
    user_id
-- @lc code=end

