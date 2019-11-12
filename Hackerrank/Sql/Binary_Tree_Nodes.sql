/*
Enter your query here.
*/
select A.n,
       (
           case
               when A.p is null then 'Root'
               when A.n in (
                   select B.p
                   from bst as B
                   where B.p is not null) then 'Inner'
               else 'Leaf'
               end
           )
from bst as A
order by A.n;