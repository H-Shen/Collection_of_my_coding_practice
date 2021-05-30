# Write your MySQL query statement below
select x.product_name, y.s as unit from Products as x
inner join
(select product_id, sum(unit) as s from Orders
where order_date >= '2020-02-01' and order_date < '2020-03-01'
group by product_id) as y
on x.product_id = y.product_id
where y.s >= 100;