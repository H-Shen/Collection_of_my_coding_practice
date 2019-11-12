/*
https://www.nowcoder.com/practice/b9068bfe5df74276bd015b9729eec4bf
*/
select A.emp_no,
       A.salary,
       (select count(distinct B.salary)
        from salaries as B
        where B.salary >= A.salary
          and B.to_date = '9999-01-01')
from salaries as A
where A.to_date = '9999-01-01'
order by A.salary desc, A.emp_no;