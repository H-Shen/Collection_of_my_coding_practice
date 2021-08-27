# Write your MySQL query statement below
select x.product_id, round(sum(x.price * y.units) / sum(y.units), 2) as average_price
from Prices as x
         inner join
         (select product_id, purchase_date, units from UnitsSold) as y
         on x.product_id = y.product_id
where y.purchase_date between x.start_date and x.end_date
group by x.product_id;