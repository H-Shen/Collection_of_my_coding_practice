# Write your MySQL query statement below
select distinct x.user_id from Confirmations as x, Confirmations as y
where x.user_id = y.user_id and timestampdiff(second, y.time_stamp, x.time_stamp) > 0 and timestampdiff(second, y.time_stamp, x.time_stamp) <= 24*60*60;