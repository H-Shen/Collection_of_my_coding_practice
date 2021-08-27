# Write your MySQL query statement below
select *
from (select gender,
             day,
             sum(current_points)
                 over (order by day) as total
      from (select gender, day, sum(score_points) as current_points
            from Scores
            where gender = 'F'
            group by day) as t1
      union all
      select gender,
             day,
             sum(current_points)
                 over (order by day) as total
      from (select gender, day, sum(score_points) as current_points
            from Scores
            where gender = 'M'
            group by day) as t2) as t
order by gender, day;