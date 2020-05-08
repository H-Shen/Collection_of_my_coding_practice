/*
Enter your query here.
*/

select ceil(avg(salary) - avg(convert(replace(concat(salary), '0', ''), decimal)))
from EMPLOYEES;