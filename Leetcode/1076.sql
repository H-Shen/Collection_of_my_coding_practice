# Write your MySQL query statement below
select distinct project_id
from Project
group by project_id
having count(employee_id) =
       (select max(x.p)
        from (select count(employee_id) as p from Project group by project_id) as x);