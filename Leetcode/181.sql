# Write your MySQL query statement below
select x.Name as Employee
from Employee as x
inner join
(select Id, Name, Salary, ManagerId from Employee) as y
on x.ManagerId = y.Id
where x.Salary > y.Salary;