/*
https://www.nowcoder.com/practice/6a62b6c0a7324350a6d9959fa7c21db3
*/
select departments.dept_no, departments.dept_name, count(salaries.from_date)
from departments,
     dept_emp,
     salaries
where salaries.emp_no = dept_emp.emp_no
  and dept_emp.dept_no = departments.dept_no
group by departments.dept_no;