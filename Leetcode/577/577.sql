# Write your MySQL query statement below
select x.name, y.bonus
from Employee as x
left join Bonus y on
x.EmpId = y.EmpId
where y.bonus is null or y.bonus < 1000;