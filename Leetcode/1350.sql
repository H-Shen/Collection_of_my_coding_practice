# Write your MySQL query statement below
select a.id, a.name from Students as a where a.department_id not in
(select b.id from Departments as b);