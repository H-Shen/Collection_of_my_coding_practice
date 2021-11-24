# Write your MySQL query statement below
select sum(k) as rich_count from (select 1 as k from Store where amount > 500 group by customer_id) as t;