/*
https://www.nowcoder.com/practice/4a052e3e1df5435880d4353eb18a91c6
*/
select distinct dept_emp.dept_no, dept_emp.emp_no, salaries.salary
from dept_emp,
     salaries
where (dept_emp.emp_no, dept_emp.from_date)
    in (select dept_emp.emp_no, max(dept_emp.from_date) from dept_emp group by dept_emp.emp_no)
  and dept_emp.emp_no = salaries.emp_no
  and (dept_emp.dept_no, salaries.salary) in
      (
          select dept_emp.dept_no, max(salaries.salary)
          from dept_emp,
               salaries
          where dept_emp.emp_no = salaries.emp_no
            and (dept_emp.emp_no, dept_emp.from_date)
              in (select dept_emp.emp_no, max(dept_emp.from_date) from dept_emp group by dept_emp.emp_no)
          group by dept_emp.dept_no
      )
order by dept_no;