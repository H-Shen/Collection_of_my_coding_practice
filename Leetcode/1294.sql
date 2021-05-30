# Write your MySQL query statement below
select z.country_name,
case
    when z.p <= 15 then 'Cold'
    when z.p >= 25 then 'Hot'
    else 'Warm'
end as weather_type
from
(select x.country_name, y.p from Countries as x
inner join
(select country_id, sum(weather_state)/count(country_id) as p from Weather where day >= '2019-11-01' and day < '2019-12-01'
group by country_id) as y
on x.country_id = y.country_id) as z;