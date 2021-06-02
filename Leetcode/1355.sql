# Write your MySQL query statement below
select x.activity from
(select count(id) as cId, activity from Friends group by activity) as x
where x.cId != (select max(t.cId) from
(select count(id) as cId from Friends group by activity) as t)
and x.cId != (select min(t.cId) from
(select count(id) as cId from Friends group by activity) as t);