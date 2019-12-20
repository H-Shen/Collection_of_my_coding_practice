/*
https://www.nowcoder.com/practice/32c53d06443346f4a2f2ca733c19660c
*/
select employees.emp_no
from employees
where employees.emp_no not in
      (select dept_manager.emp_no
       from dept_manager);