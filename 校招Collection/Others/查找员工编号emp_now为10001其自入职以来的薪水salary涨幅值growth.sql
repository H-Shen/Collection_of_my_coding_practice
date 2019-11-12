/*
https://www.nowcoder.com/practice/c727647886004942a89848e2b5130dc2
*/
select max(salaries.salary) - min(salaries.salary)
from salaries
where salaries.emp_no = 10001;