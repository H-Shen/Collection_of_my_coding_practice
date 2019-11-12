/*
Enter your query here.
*/
select distinct hackers.hacker_id, hackers.name, sum(score) as f
from hackers
         inner join
     (
         select Submissions.hacker_id, max(Submissions.score) as score
         from Submissions
         group by Submissions.challenge_id, Submissions.hacker_id
     ) maxScore
     on hackers.hacker_id = maxScore.hacker_id
group by hackers.hacker_id, hackers.name
having f > 0
order by f desc, hackers.hacker_id;