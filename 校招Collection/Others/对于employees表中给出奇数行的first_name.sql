/*
https://www.nowcoder.com/practice/e3cf1171f6cc426bac85fd4ffa786594
*/
select e1.first_name
from employees as e1
where (select count(*) + 1 from employees as e2 where e2.first_name < e1.first_name) % 2 = 1;