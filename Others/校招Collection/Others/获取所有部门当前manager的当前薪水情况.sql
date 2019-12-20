/*
https://www.nowcoder.com/practice/4c8b4a10ca5b44189e411107e1d8bec1
*/
select dept_manager.dept_no, dept_manager.emp_no, salaries.salary
from dept_manager,
     salaries
where salaries.emp_no = dept_manager.emp_no
  and dept_manager.to_date = '9999-01-01'
  and (salaries.emp_no, salaries.from_date)
    in
      (select salaries.emp_no, max(salaries.from_date)
       from salaries
       group by salaries.emp_no);