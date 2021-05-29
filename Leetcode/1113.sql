# Write your MySQL query statement below
select a.extra as report_reason, count(distinct a.post_id) as report_count from Actions as a
where a.action_date = '2019-07-04' and a.action = 'report'
group by a.extra;