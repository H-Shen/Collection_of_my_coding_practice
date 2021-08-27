# Write your MySQL query statement below
with cte as (
    select t.name as caller_country_name, t2.name as callee_country_name, z.duration as duration
             from Calls as z
                , (select x.name, y.id as person_id
                   from Country as x,
                        (select id, substr(phone_number, 1, 3) as cc from Person) as y
                   where x.country_code = y.cc) as t
                , (select x.name, y.id as person_id
                   from Country as x,
                        (select id, substr(phone_number, 1, 3) as cc from Person) as y
                   where x.country_code = y.cc) as t2
             where z.caller_id = t.person_id
               and z.callee_id = t2.person_id
)
select t5.name as country
from
(select name, duration from Country, cte
where name = caller_country_name
union all
select name, duration from Country, cte
where name = callee_country_name) as t5
group by t5.name
having sum(t5.duration) / count(t5.duration) > (select sum(duration) / count(duration) from Calls);