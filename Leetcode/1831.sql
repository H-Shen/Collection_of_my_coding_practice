# Write your MySQL query statement below
select t.transaction_id
from Transactions as t
where (t.amount, year(t.day), month(t.day), day(t.day)) in
      (select t2.a, t2.y, t2.m, t2.d
       from (select max(amount) as a, year(day) as y, month(day) as m, day(day) as d
             from Transactions
             group by year(day), month(day), day(day)) as t2)
order by t.transaction_id;