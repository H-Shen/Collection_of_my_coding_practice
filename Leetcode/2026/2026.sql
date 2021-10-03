# Write your MySQL query statement below
select problem_id
from Problems
where likes * 100 / (likes + dislikes) < 60.0
order by problem_id;