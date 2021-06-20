# Write your MySQL query statement below
select distinct t1.student_name as member_A, t2.student_name as member_B, t3.student_name as member_C from SchoolA as t1, SchoolB as t2, SchoolC as t3
where t1.student_id != t2.student_id and t1.student_id != t3.student_id and t2.student_id != t3.student_id
and t1.student_name != t2.student_name and t1.student_name != t3.student_name and t2.student_name != t3.student_name;