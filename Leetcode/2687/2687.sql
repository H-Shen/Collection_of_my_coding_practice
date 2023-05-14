# Write your MySQL query statement below
select a.bike_number, a.end_time
from (select bike_number, max(end_time) as end_time
      from Bikes
      group by bike_number) as a,

     (select bike_number, max(start_time) as stime
      from Bikes
      group by bike_number) as b
where a.bike_number = b.bike_number
order by b.stime desc;