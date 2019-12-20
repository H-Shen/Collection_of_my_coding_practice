/*
https://www.nowcoder.com/practice/8fe212a6c71b42de9c15c56ce354bebe
*/
select dept_emp.dept_no, dept_emp.emp_no, salaries.salary
from dept_emp,
     salaries
where dept_emp.to_date = '9999-01-01'
  and salaries.to_date = '9999-01-01'
  and dept_emp.emp_no = salaries.emp_no
  and dept_emp.emp_no not in
      (select dept_manager.emp_no
       from dept_manager
       where dept_manager.to_date = '9999-01-01');