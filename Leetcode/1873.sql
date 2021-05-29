# Write your MySQL query statement below
select employee_id,
       IF(mod(employee_id, 2) = 1 and name not rlike '^M', salary, 0) as bonus
from Employees;
