/*
https://www.nowcoder.com/practice/d3b058dcc94147e09352eb76f93b3274
*/
update salaries
set salary = 1.1 * salary
where to_date = '9999-01-01'
  and emp_no in
      (select distinct emp_bonus.emp_no from emp_bonus);