# Write your MySQL query statement below
select x.name as name, ifnull(y.rt,0) as rest, ifnull(y.p,0) as paid, ifnull(y.c,0) as canceled, ifnull(y.rf,0) as refunded from Product as x
left join
(select product_id, sum(rest) as rt, sum(paid) as p, sum(canceled) as c, sum(refunded) as rf from Invoice group by product_id) as y
on x.product_id = y.product_id
order by x.name;