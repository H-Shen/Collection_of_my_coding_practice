# Write your MySQL query statement below
select
    distinct
    t1.symbol as metal,
    t2.symbol as nonmetal
from
    Elements as t1,
    Elements as t2
where
    t1.type = 'Metal'
    and
    t2.type = 'Nonmetal';
