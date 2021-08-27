# Write your MySQL query statement below
select name as warehouse_name, sum(unit_volume * units) as volume
from (select t2.name, t1.Width * t1.Length * t1.Height as unit_volume, t2.units
      from Products as t1,
           Warehouse as t2
      where t1.product_id = t2.product_id) as t
group by name;