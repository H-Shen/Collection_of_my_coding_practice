# Write your MySQL query statement below
select
    distinct Rides.driver_id,
    if(t.cnt is null, 0, t.cnt) as cnt
from
    Rides
left join
(select
    Rides.passenger_id,
    count(Rides.passenger_id) as cnt
from
    Rides
where
    Rides.passenger_id
in
    (select Rides.driver_id
     from Rides)
group by
    Rides.passenger_id) as t
on Rides.driver_id = t.passenger_id;