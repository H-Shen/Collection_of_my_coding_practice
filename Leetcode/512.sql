# Write your MySQL query statement below
select x.player_id, x.device_id
from Activity as x
         inner join
     (select player_id, min(event_date) as first_login from Activity group by player_id) as y
     on
         x.player_id = y.player_id and x.event_date = y.first_login;