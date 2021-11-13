# Write your MySQL query statement below
select case
           when (select count(student_id) from NewYork where score >= 90) >
                (select count(student_id) from California where score >= 90) then 'New York University'
           when (select count(student_id) from NewYork where score >= 90) <
                (select count(student_id) from California where score >= 90) then 'California University'
           else 'No Winner'
           end as winner;