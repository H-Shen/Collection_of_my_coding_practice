# Write your MySQL query statement below
select t.departmentName as Department, t.personName as Employee, t.Salary
from (select x.Name as personName, x.Salary, x.DepartmentId, y.Name as departmentName
      from Employee as x,
           Department as y
      where x.DepartmentId = y.Id) as t
where (t.Salary, t.DepartmentId) in
      (select max(Salary) as ms, DepartmentId from Employee group by DepartmentId);