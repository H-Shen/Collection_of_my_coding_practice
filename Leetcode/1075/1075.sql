# Write your MySQL query statement below
select y.project_id, round(sum(x.experience_years) / count(x.experience_years), 2) as average_years
from Employee as x
         inner join
         (select project_id, employee_id from Project) as y
         on x.employee_id = y.employee_id
group by project_id;