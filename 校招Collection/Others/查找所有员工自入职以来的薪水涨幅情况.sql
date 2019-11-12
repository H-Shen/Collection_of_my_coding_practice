/*
https://www.nowcoder.com/practice/fc7344ece7294b9e98401826b94c6ea5
*/
select a.emp_no, (b.salary - c.salary) as growth
from employees as a
         inner join salaries as b
                    on a.emp_no = b.emp_no and b.to_date = '9999-01-01'
         inner join salaries as c
                    on a.emp_no = c.emp_no and a.hire_date = c.from_date
order by growth;