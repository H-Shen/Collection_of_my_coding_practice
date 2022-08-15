# Write your MySQL query statement below
select
    d.salesperson_id,
    d.name,
    if(t.total is null, 0, t.total) as total
from
    Salesperson as d
left join
(select
    a.salesperson_id,
    c.name,
    sum(b.price) as total
from
    Customer as a, Sales as b, Salesperson as c
where
    a.customer_id = b.customer_id
and
    a.salesperson_id = c.salesperson_id
group by
    a.salesperson_id, c.name) as t
on t.salesperson_id = d.salesperson_id;