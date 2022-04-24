# Write your MySQL query statement below
select
    lower(trim(Sales.product_name)) as product_name,
    date_format(Sales.sale_date, '%Y-%m') as sale_date,
    count(Sales.sale_id) as total
from
    Sales
group by
    lower(trim(Sales.product_name)),
    date_format(Sales.sale_date, '%Y-%m')
order by
    lower(trim(Sales.product_name)),
    date_format(Sales.sale_date, '%Y-%m');