/*
Enter your query here.
*/
select name, grade, marks
from Students,
     Grades
where (marks >= Grades.min_mark and marks <= Grades.max_mark)
  and grade >= 8
order by grade desc, name;

select 'NULL', grade, marks
from Students,
     Grades
where (marks >= Grades.min_mark and marks <= Grades.max_mark)
  and grade < 8
order by grade desc, marks;