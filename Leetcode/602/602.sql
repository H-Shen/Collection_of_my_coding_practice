# Write your MySQL query statement below
select t.id, sum(t.num) as num
from
(select
    requester_id as id,
    count(distinct accepter_id) as num
from RequestAccepted
group by requester_id
union all
(select accepter_id                  as id,
        count(distinct requester_id) as num
 from RequestAccepted
 group by accepter_id)
) as t
group by t.id
order by num desc limit 1;