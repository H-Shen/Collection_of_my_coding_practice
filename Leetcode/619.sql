# Write your MySQL query statement below
select max(distinct x.num) as num
from my_numbers as x
inner join
(select num, count(num) as freq from my_numbers group by num) as y
on x.num = y.num and y.freq = 1;