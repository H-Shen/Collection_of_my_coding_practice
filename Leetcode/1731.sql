# Write your MySQL query statement below
select x.employee_id, x.name, y.reports_count, y.average_age from Employees as x
inner join
(select round(sum(age)/count(employee_id)) as average_age , count(employee_id) as reports_count, reports_to from Employees
where reports_to is not null
group by reports_to) as y
on x.employee_id = y.reports_to
order by x.employee_id;