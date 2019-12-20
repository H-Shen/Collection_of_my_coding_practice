/*
https://www.nowcoder.com/practice/74d90728827e44e2864cce8b26882105
*/
select employees.first_name from employees
order by substr(employees.first_name, length(employees.first_name) - 1);