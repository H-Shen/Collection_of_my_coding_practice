/*
Enter your query here.
*/
set @maximal_earnings = (select max(salary * months)
                         from employee);
set @count_of_people = (select count(employee_id)
                        from employee
                        where salary * months = @maximal_earnings);
select concat(@maximal_earnings, '  ', @count_of_people);