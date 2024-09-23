/*
https://www.nowcoder.com/practice/e50d92b8673a440ebdf3a517b5b37d62
*/
select distinct dept_emp.emp_no, dept_manager.emp_no
from dept_emp,
     dept_manager
where dept_emp.dept_no = dept_manager.dept_no
  and dept_manager.to_date = '9999-01-01'
  and (dept_manager.dept_no, dept_manager.from_date) in
      (select dept_manager.dept_no, max(dept_manager.from_date) from dept_manager group by dept_manager.dept_no)
  and dept_emp.emp_no <> dept_manager.emp_no;