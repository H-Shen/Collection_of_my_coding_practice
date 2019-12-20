/* https://www.nowcoder.com/practice/dbfafafb2ee2482aa390645abd4463bf */
select distinct employees.last_name,
                employees.first_name,
                dept_emp.dept_no
from employees
         left join dept_emp
                   on dept_emp.emp_no = employees.emp_no;