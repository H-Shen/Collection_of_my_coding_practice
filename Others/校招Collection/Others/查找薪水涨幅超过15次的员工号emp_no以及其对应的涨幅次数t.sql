/*
https://www.nowcoder.com/practice/6d4a4cff1d58495182f536c548fee1ae
*/
select salaries.emp_no, count(salaries.emp_no) as t
from salaries
group by salaries.emp_no
having t > 15;