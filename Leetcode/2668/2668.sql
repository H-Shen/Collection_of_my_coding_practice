# Write your MySQL query statement below

select
    distinct a.emp_id, b.firstname, b.lastname, a.salary, b.department_id
from
(select
    emp_id, max(salary) as salary
from
    Salary
group by
    emp_id) a, Salary as b
where
    a.emp_id = b.emp_id
order by
    a.emp_id;