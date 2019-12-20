/*
https://www.nowcoder.com/practice/5cdbf1dcbe8d4c689020b6b2743820bf
*/
select employees.emp_no,
       employees.first_name,
       employees.last_name,
       emp_bonus.btype,
       salaries.salary,
       (case emp_bonus.btype
            when 1 then salaries.salary * 0.1
            when 2 then salaries.salary * 0.2
            else salaries.salary * 0.3
           end)
from employees,
     salaries,
     emp_bonus
where employees.emp_no = salaries.emp_no
  and salaries.to_date = '9999-01-01'
  and employees.emp_no = emp_bonus.emp_no;