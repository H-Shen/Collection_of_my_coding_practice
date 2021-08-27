# Write your MySQL query statement below
select concat(z.y,'-',lpad(z.m, 2, '00')) as month, z.order_count, z.customer_count from
(select year(order_date) as y, month(order_date) as m, count(distinct order_id) as order_count, count(distinct customer_id) as customer_count from Orders
where invoice > 20
group by m, y) as z;