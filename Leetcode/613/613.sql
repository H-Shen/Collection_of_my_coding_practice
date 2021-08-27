# Write your MySQL query statement below
select min(abs(a.x-b.x)) as shortest from point as a cross join point as b
where abs(a.x-b.x) != 0;
