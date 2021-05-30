# Write your MySQL query statement below
select distinct title from Content
where Kids_content = 'Y' and content_id in
(select content_id from TVProgram where program_date >= '2020-06-01' and program_date < '2020-07-01')
and content_type = 'Movies';