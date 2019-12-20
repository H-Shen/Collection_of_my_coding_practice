/*
https://www.nowcoder.com/practice/ae51e6d057c94f6d891735a48d1c2397
*/
select distinct salaries.salary
from salaries
where to_date = '9999-01-01'
  and (salaries.emp_no, salaries.from_date) in
      (select salaries.emp_no, max(salaries.from_date) from salaries group by salaries.emp_no)
order by salaries.salary desc