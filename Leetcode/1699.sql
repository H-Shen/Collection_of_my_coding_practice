# Write your MySQL query statement below
select if(from_id > to_id, to_id, from_id) as person1,
       if(from_id > to_id, from_id, to_id) as person2,
       count(duration)                     as call_count,
       sum(duration)                       as total_duration
from Calls
group by person1, person2;