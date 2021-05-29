# Write your MySQL query statement below
select x.name,
       IF(y.distance is null, 0, y.distance) as travelled_distance from Users as x
left outer join
(select user_id, sum(distance) as distance from Rides group by user_id) as y
on x.id = y.user_id
order by travelled_distance desc , x.name;
