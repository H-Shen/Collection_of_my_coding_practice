# Write your MySQL query statement below
select a                                               as platform,
       b                                               as experiment_name,
       IF((a, b) in (select platform, experiment_name from Experiments),
          (select count(z.experiment_id)
           from Experiments as z
           where z.platform = a
             and z.experiment_name = b
           group by z.platform, z.experiment_name), 0) as num_experiments
from (select *
      from (select 'IOS' as a union select 'Android' union select 'Web') as t
               join
               (select 'Reading' as b union select 'Sports' union select 'Programming') as t2) as t3;