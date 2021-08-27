# Write your MySQL query statement below
select distinct product_id, 10 price from Products where product_id not in
(
    select t1.product_id
    from Products as t1,
         (select product_id, max(change_date) as ms
          from Products
          where change_date <= '2019-08-16'
          group by product_id) as t2
    where (t1.product_id, t1.change_date) = (t2.product_id, t2.ms)
)
union
(    select distinct t1.product_id, t1.new_price as price
    from Products as t1,
         (select product_id, max(change_date) as ms
          from Products
          where change_date <= '2019-08-16'
          group by product_id) as t2
    where (t1.product_id, t1.change_date) = (t2.product_id, t2.ms));