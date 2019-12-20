/*
https://www.nowcoder.com/practice/c59b452f420c47f48d9c86d69efdff20
*/
select titles.title, count(distinct titles.emp_no) as t
from titles
group by titles.title;