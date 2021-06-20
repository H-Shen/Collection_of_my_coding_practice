# Write your MySQL query statement below
select t.sell_date, count(t.product) as num_sold, group_concat(t.product order by t.product) as products from
(select distinct sell_date, product from Activities) as t
group by t.sell_date
order by t.sell_date;