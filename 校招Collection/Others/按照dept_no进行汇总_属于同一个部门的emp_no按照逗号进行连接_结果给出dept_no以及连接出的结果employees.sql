/*
https://www.nowcoder.com/practice/6e86365af15e49d8abe2c3d4b5126e87
*/
select dept_no, group_concat(emp_no, ',')
from dept_emp
group by dept_no;