/*
https://www.nowcoder.com/practice/95078e5e1fba4438b85d9f11240bc591
*/
select avg(salaries.salary)
from salaries
where salaries.salary <>
      (select max(salaries.salary)
       from salaries)
  and salaries.salary <>
      (select min(salaries.salary)
       from salaries)
  and salaries.to_date = '9999-01-01';