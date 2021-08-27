# Write your MySQL query statement below
select round(sqrt(min((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y))),2) as shortest from point_2d as t1, point_2d as t2
where not (t1.x = t2.x and t1.y = t2.y);