# Write your MySQL query statement below
select t1.employee_id, t2.team_size from Employee as t1
inner join
(select team_id, count(team_id) as team_size from Employee group by team_id) as t2
on t1.team_id = t2.team_id;
