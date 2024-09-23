/*
https://www.nowcoder.com/practice/72ca694734294dc78f513e147da7821e
*/
select titles.title, count(titles.emp_no) as t
from titles
group by titles.title;