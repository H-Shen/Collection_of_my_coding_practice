# Write your MySQL query statement below
select x.sale_date, sum(x.diff) as diff from
(select sale_date,
       IF(fruit = 'apples', sold_num, -sold_num) as diff
from Sales) as x
group by x.sale_date
order by x.sale_date;