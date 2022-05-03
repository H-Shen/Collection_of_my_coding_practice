# Write your MySQL query statement below
select t.login_date, count(t.user_id) as user_count from
    (select user_id,
               min(activity_date) as login_date
        from Traffic
        where activity = 'login'
        group by user_id
        having min(activity_date) >= date_sub('2019-06-30', interval 90 day)) as t
group by
    t.login_date;