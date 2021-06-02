# Write your MySQL query statement below
select ids from
(select b*10+a as ids from
(select 0 a union all select 1 union all select 2 union all select 3 union all select 4 union all select 5 union all select 6 union all select 7 union all select 8 union all select 9) t1,
(select 0 b union all select 1 union all select 2 union all select 3 union all select 4 union all select 5 union all select 6 union all select 7 union all select 8 union all select 9) t2
order by 1) as t    -- generate numbers from 1-100
where ids >= 1 and ids <= (select max(customer_id) from Customers)
and ids not in (select customer_id from Customers)
order by ids;