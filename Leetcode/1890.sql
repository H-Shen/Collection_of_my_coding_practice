# Write your MySQL query statement below
select t.user_id, max(t.time_stamp) as last_stamp from
(select user_id, time_stamp from Logins where time_stamp between '2020-01-01 00:00:00' and '2020-12-31 23:59:59') as t
group by t.user_id;