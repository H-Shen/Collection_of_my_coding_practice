# Write your MySQL query statement below
select distinct t1.buyer_id
from (select x.buyer_id
      from Sales as x
      where x.buyer_id not in
            (select s.buyer_id
             from Sales as s
             where s.product_id in (select product_id from Product where product_name = 'iPhone'))) as t1
where t1.buyer_id in
      (select y.buyer_id
       from Sales as y
       where y.product_id in
             (select product_id from Product where product_name = 'S8'));