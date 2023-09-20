# Write your MySQL query statement below
select t2.user_id, t3.name, t2.distance as `traveled distance`
from (select t.user_id,
             sum(t.distance) as distance
      from (select user_id,
                   0 as distance
            from Users
            union
            select user_id,
                   sum(distance) as distance
            from Rides
            group by user_id) as t
      group by t.user_id) as t2,
     Users as t3
where t2.user_id = t3.user_id
order by t2.user_id;