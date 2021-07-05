# Write your MySQL query statement below
select t.followee as follower, count(distinct t.follower) as num from follow as t
where t.followee in (select follower from follow where follower in (select followee from follow))
group by t.followee order by t.followee;