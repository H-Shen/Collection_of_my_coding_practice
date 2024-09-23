/*
https://www.nowcoder.com/practice/a32669eb1d1740e785f105fa22741d5c
*/
select distinct employees.emp_no,
                employees.birth_date,
                employees.first_name,
                employees.last_name,
                employees.gender,
                employees.hire_date
from employees
where employees.emp_no % 2 = 1
  and employees.last_name <> 'Mary'
order by hire_date desc;