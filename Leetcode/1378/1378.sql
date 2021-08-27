# Write your MySQL query statement below
select a.unique_id, b.name from EmployeeUNI as a
right outer join Employees as b
on a.id = b.id;
