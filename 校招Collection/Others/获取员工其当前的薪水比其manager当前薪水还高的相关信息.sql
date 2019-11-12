/*
https://www.nowcoder.com/practice/f858d74a030e48da8e0f69e21be63bef
*/
select dept_emp.emp_no,
       dept_manager.emp_no,
       A.salary,
       B.salary
from dept_emp,
     dept_manager,
     salaries as A,
     salaries as B
where dept_emp.to_date = '9999-01-01'
  and dept_manager.to_date = '9999-01-01'
  and A.to_date = '9999-01-01'
  and B.to_date = '9999-01-01'
  and dept_emp.dept_no = dept_manager.dept_no
  and A.emp_no = dept_emp.emp_no
  and B.emp_no = dept_manager.emp_no
  and A.salary > B.salary;