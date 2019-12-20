/*
https://www.nowcoder.com/practice/4bcb6a7d3e39423291d2f7bdbbff87f8
*/
select dept_emp.dept_no,
       departments.dept_name,
       titles.title,
       count(titles.title)
from departments,
     titles,
     dept_emp
where dept_emp.to_date = '9999-01-01'
  and titles.to_date = '9999-01-01'
  and dept_emp.dept_no = departments.dept_no
  and dept_emp.emp_no = titles.emp_no
group by dept_emp.dept_no, departments.dept_name, titles.title;