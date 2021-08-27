# Write your MySQL query statement below
select round(
                       (select count(z.delivery_id)
                        from (select x.delivery_id, x.order_date, x.customer_pref_delivery_date
                              from Delivery as x
                                       inner join
                                   (select customer_id, min(order_date) as m from Delivery group by customer_id) as y
                                   on x.customer_id = y.customer_id and x.order_date = y.m) as z
                        where z.customer_pref_delivery_date = z.order_date) * 100 /
                       (select count(z.delivery_id)
                        from (select x.delivery_id
                              from Delivery as x
                                       inner join
                                   (select customer_id, min(order_date) as m from Delivery group by customer_id) as y
                                   on x.customer_id = y.customer_id and x.order_date = y.m) as z),
                       2) as immediate_percentage;