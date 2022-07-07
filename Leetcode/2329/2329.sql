# Write your MySQL query statement below
select
    Sales.user_id,
    sum(Sales.quantity * Product.price) as spending
from
    Sales,
    Product
where
    Sales.product_id = Product.product_id
group by
    Sales.user_id
order by
    spending desc,
    Sales.user_id
;
