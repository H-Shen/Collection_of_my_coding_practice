# Write your MySQL query statement below
select id,
case
    when id in (select id from tree where p_id is null) then 'Root'
    when id in (select id from tree where id not in (select p_id from tree where p_id is not null)) then 'Leaf'
    else 'Inner'
end as Type
from tree;
