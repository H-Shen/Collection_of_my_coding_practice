# Write your MySQL query statement below

select max(t3.salary) - min(t3.salary) as salary_difference
from (select max(t1.salary) as salary
      from Salaries as t1
      where t1.department = 'Engineering'
      union
      (select max(t2.salary) as salary
       from Salaries as t2
       where t2.department = 'Marketing')) as t3;