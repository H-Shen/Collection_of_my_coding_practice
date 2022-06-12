# Write your MySQL query statement below
select t1.weekend_cnt, t2.working_cnt
from (select count(task_id) as weekend_cnt
      from Tasks
      where dayofweek(submit_date) = 1
         or dayofweek(submit_date) = 7) as t1
        ,
     (select count(task_id) as working_cnt
      from Tasks
      where dayofweek(submit_date) != 1
         and dayofweek(submit_date) != 7) as t2;