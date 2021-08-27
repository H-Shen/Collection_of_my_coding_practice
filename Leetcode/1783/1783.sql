# Write your MySQL query statement below
select y.player_id, y.player_name, t.grand_slams_count
from Players as y,
     (select count(x.year) as grand_slams_count, x.c
      from (((select year, Wimbledon as c
              from Championships
              union all
              select year, Fr_open as c
              from Championships)
             union all
             select year, US_open as c
             from Championships)
            union all
            select year, Au_open as c
            from Championships) as x
      group by x.c) as t
where y.player_id = t.c;