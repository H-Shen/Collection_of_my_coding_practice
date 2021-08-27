# Write your MySQL query statement below
select distinct x.class from courses as x
inner join
(select class, count(distinct student, class) as p from courses group by class) as y
on x.class = y.class where y.p >= 5;
