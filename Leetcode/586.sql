# Write your MySQL query statement below
select distinct customer_number from orders group by customer_number
having count(order_number) = (select max(p) from (select count(order_number) as p from orders group by customer_number) t);