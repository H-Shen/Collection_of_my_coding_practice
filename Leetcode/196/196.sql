# Write your MySQL query statement below
delete from Person as x where x.Id not in
(select t.mId from (select min(Id) as mId from Person group by Email) as t);