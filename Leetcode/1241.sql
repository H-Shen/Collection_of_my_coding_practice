# Write your MySQL query statement below
select distinct S.sub_id as post_id,
                IF(S.sub_id in
                   (select parent_id
                    from Submissions
                    where parent_id in (select sub_id from Submissions where parent_id is null)
                    group by parent_id), (select count(distinct t.sub_id)
                                          from Submissions as t
                                          where t.parent_id = S.sub_id
                                          group by t.parent_id), 0) as number_of_comments
from Submissions as S
where S.parent_id is null
order by post_id;