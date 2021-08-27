# Write your MySQL query statement below
select if((select count(distinct a.Salary) from Employee as a) < 2, null, (select max(c.Salary) from Employee as c where c.Salary != (select max(b.Salary) from Employee as b))) as SecondHighestSalary;
