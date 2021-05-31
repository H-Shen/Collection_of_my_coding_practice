# Write your MySQL query statement below
select e.Name from Employee as e where e.Id in
(select ManagerId from Employee where ManagerId is not null
group by ManagerId
having count(Id) >= 5);