/*
https://www.nowcoder.com/practice/c39cbfbd111a4d92b221acec1c7c1484
*/
select employees.emp_no,
       employees.birth_date,
       employees.first_name,
       employees.last_name,
       employees.gender,
       employees.hire_date
from employees
where not exists(select dept_emp.emp_no
                 from dept_emp
                 where dept_emp.emp_no = employees.emp_no);