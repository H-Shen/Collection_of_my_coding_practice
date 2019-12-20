/*
https://www.nowcoder.com/practice/c8652e9e5a354b879e2a244200f1eaae
*/
select titles.title, avg(salaries.salary)
from titles,
     salaries
where salaries.emp_no = titles.emp_no
  and salaries.to_date = '9999-01-01'
  and titles.to_date = '9999-01-01'
group by titles.title;