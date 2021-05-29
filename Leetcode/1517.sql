# Write your MySQL query statement below
select user_id, name, mail from Users
where mail rlike '^[A-Za-z][A-Za-z0-9_.-]*@leetcode.com$';
