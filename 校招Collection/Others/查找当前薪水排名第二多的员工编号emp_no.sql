/*
https://www.nowcoder.com/practice/c1472daba75d4635b7f8540b837cc719
*/
select employees.emp_no, salaries.salary, employees.last_name, employees.first_name
from employees,
     salaries
where employees.emp_no = salaries.emp_no
  and salaries.to_date = '9999-01-01'
  and salaries.salary =
      (
          select max(salaries.salary)
          from salaries
          where salaries.to_date = '9999-01-01'
            and salaries.salary <>
                (
                    select max(salaries.salary) from salaries where salaries.to_date = '9999-01-01'
                )
      );