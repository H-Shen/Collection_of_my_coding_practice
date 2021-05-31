# Write your MySQL query statement below
select x.student_id, min(x.course_id) as course_id, x.grade
from Enrollments as x
         inner join
     (select student_id, max(grade) as mg from Enrollments group by student_id) as y
     on x.student_id = y.student_id
where x.grade = y.mg
group by x.grade, x.student_id
order by x.student_id;