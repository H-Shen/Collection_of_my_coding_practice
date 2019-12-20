/*
 https://www.nowcoder.com/practice/23142e7a23e4480781a3b978b5e0f33a
*/
select distinct employees.emp_no, salaries.salary
from employees,
     salaries
where employees.emp_no = salaries.emp_no

  and (employees.emp_no, salaries.to_date) in (select employees.emp_no, min(salaries.to_date)
                                               from salaries,
                                                    employees
                                               where employees.emp_no = salaries.emp_no
                                               group by employees.emp_no)

order by employees.emp_no desc;