# Write your MySQL query statement below
select x.dept_name,
       IF(x.dept_id in (select dept_id from student group by dept_id),
          (select count(student_id) as c from student where dept_id = x.dept_id group by dept_id), 0) as student_number
from department as x
order by student_number desc, x.dept_name;