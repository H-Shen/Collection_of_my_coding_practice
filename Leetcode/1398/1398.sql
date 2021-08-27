# Write your MySQL query statement below
select distinct x.customer_id, x.customer_name
from Customers as x
where x.customer_id in
      (select customer_id from Orders where product_name = 'A')
  and x.customer_id in
      (select customer_id from Orders where product_name = 'B')
  and x.customer_id in
      (select customer_id
       from Customers
       where customer_id not in
             (select customer_id from Orders where product_name = 'C'))
group by x.customer_id;