/*
https://www.nowcoder.com/practice/58824cd644ea47d7b2b670c506a159a6
*/
select b.emp_no
     , b.salary
     , (
    select sum(a.salary)
    from (select * from salaries where salaries.to_date = '9999-01-01') as a
    where a.emp_no <= b.emp_no
) as cumulative_sum
from (select * from salaries where salaries.to_date = '9999-01-01') as b
order by b.emp_no;