# Write your MySQL query statement below
select t.email_domain, t.count
from
(select 
    substring(email from (LOCATE('@',email)+1))
    as email_domain, count(*) as `count`
from
    Emails
group by
    email_domain
) as t
where
    right(t.email_domain,4) = '.com'
order by
    t.email_domain
;
