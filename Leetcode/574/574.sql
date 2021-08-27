# Write your MySQL query statement below
select x.Name
from Candidate as x
where x.id in
      (select distinct CandidateId
       from Vote
       group by CandidateId
       having count(id) =
              (select max(t1.p)
               from (select count(id) as p from Vote group by CandidateId) as t1));

