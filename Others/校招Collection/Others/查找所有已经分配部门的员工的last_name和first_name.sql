/* https://www.nowcoder.com/practice/6d35b1cd593545ab985a68cd86f28671 */
select distinct employees.last_name, employees.first_name, dept_emp.dept_no
from dept_emp,
     employees
where dept_emp.emp_no = employees.emp_no;