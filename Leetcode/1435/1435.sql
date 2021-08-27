# Write your MySQL query statement below
select '[0-5>' as bin, sum(if(duration >= 0 and duration < 5*60, 1, 0)) as total from Sessions
union
select '[5-10>' as bin, sum(if(duration >= 5*60 and duration < 10*60, 1, 0)) as total from Sessions
union
select '[10-15>' as bin, sum(if(duration >= 10*60 and duration < 15*60, 1, 0)) as total from Sessions
union
select '15 or more' as bin, sum(if(duration > 15*60, 1, 0)) as total from Sessions;