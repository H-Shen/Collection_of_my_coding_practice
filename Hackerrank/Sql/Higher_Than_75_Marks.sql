/*
Enter your query here.
*/
select name
from students
where marks > 75
order by right(rtrim(name), 3), id;