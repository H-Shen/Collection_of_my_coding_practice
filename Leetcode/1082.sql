# Write your MySQL query statement below
select distinct seller_id
from Sales
group by seller_id
having sum(price) =
       (select max(x.sp)
        from (select sum(price) as sp from Sales group by seller_id) as x);