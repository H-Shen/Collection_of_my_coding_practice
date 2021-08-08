# Write your MySQL query statement below
select distinct t.employee_id
from (select employee_id
      from Employees
      where employee_id not in (select employee_id from Salaries)
      union
      (select employee_id from Salaries where employee_id not in (select employee_id from Employees))) as t
order by t.employee_id;