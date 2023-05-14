# Write your MySQL query statement below
select c.order_date, c.immediate_percentage
from (select a.order_date,
             round(a.cnt / b.cnt * 100.0, 2) as immediate_percentage
      from (select count(delivery_id) as cnt, order_date
            from Delivery
            where order_date = customer_pref_delivery_date
            group by order_date) as a,

           (select count(delivery_id) as cnt, order_date
            from Delivery
            group by order_date) as b
      where a.order_date = b.order_date

      union all

      select distinct order_date, 0
      from Delivery
      where order_date not in
            (select order_date
             from Delivery
             where customer_pref_delivery_date = order_date)) as c
order by
    c.order_date;