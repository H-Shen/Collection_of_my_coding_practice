# Write your MySQL query statement below
select distinct x.Id from Weather as x, Weather as y
where datediff(x.RecordDate, y.RecordDate) = 1 and x.Temperature > y.Temperature;
