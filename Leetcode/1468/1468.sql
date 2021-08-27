# Write your MySQL query statement below
select z.company_id,
       z.employee_id,
       z.employee_name,
       case
           when z.ms < 1000 then z.salary
           when z.ms >= 1000 and z.ms <= 10000 then round(z.salary * (1 - 0.24))
           else round(z.salary * (1 - 0.49))
           end as salary
from (
         select x.company_id, x.employee_id, x.employee_name, x.salary, y.ms
         from Salaries as x,
              (select company_id, max(salary) as ms from Salaries group by company_id) as y
         where x.company_id = y.company_id) as z;