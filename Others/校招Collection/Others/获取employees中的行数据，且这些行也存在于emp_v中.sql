/*
https://www.nowcoder.com/practice/2556c1fcc92c490d9bf331ab07dfb7dc
*/
select employees.emp_no,
       employees.birth_date,
       employees.first_name,
       employees.last_name,
       employees.gender,
       employees.hire_date
from employees
where (employees.emp_no, employees.birth_date, employees.first_name,
       employees.last_name, employees.gender, employees.hire_date) in
      (select emp_v.emp_no,
              emp_v.birth_date,
              emp_v.first_name,
              emp_v.last_name,
              emp_v.gender,
              emp_v.hire_date
       from emp_v);