/*
https://www.nowcoder.com/practice/8d2c290cc4e24403b98ca82ce45d04db
*/
select salaries.emp_no, salaries.salary
from salaries
order by salaries.salary desc
limit 1, 1;