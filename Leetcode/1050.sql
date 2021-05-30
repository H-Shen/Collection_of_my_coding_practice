# Write your MySQL query statement below
select distinct x.actor_id, x.director_id from ActorDirector as x
inner join
(select actor_id, director_id, count(timestamp) as freq from ActorDirector group by actor_id, director_id) as y
on x.actor_id = y.actor_id and x.director_id = y.director_id and y.freq >= 3;