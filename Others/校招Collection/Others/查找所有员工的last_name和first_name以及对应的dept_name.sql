/*
https://www.nowcoder.com/practice/5a7975fabe1146329cee4f670c27ad55
*/
select distinct employees.last_name, employees.first_name, departments.dept_name
from employees
         left join dept_emp on employees.emp_no = dept_emp.emp_no
         left join departments on dept_emp.dept_no = departments.dept_no;