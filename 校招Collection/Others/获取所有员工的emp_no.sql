/*
https://www.nowcoder.com/practice/e2dab5477fdd4ec0ba84031f8e817b8a
*/
select employees.emp_no, dept_emp.dept_no, emp_bonus.btype, emp_bonus.recevied
from employees
         inner join dept_emp on employees.emp_no = dept_emp.emp_no
         left join emp_bonus on employees.emp_no = emp_bonus.emp_no;