/*
https://www.nowcoder.com/practice/eb9b13e5257744db8265aa73de04fd44
*/
select B.emp_no, B.from_date, (B.salary - A.salary) as salary_growth
from salaries as B,
     salaries as A
where A.emp_no = B.emp_no
  and salary_growth > 5000
  and (strftime("%Y", B.to_date) - strftime("%Y", A.to_date) = 1 or
       strftime("%Y", B.from_date) - strftime("%Y", A.from_date) = 1)
order by salary_growth desc;