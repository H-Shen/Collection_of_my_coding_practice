/* https://www.nowcoder.com/practice/c63c5b54d86e4c6d880e4834bfd70c3b */
select distinct salaries.emp_no,
                max(salaries.salary),
                max(salaries.from_date),
                max(dept_manager.to_date),
                max(dept_manager.dept_no)
from salaries,
     dept_manager
where dept_manager.emp_no = salaries.emp_no
  and dept_manager.to_date = '9999-01-01'
group by salaries.emp_no;