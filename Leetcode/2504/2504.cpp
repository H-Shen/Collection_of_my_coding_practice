# Write your MySQL query statement below
select
    Person.person_id as person_id,
    concat(Person.name, '(', substring(Person.profession, 1, 1), ')') as name
from
    Person
order by
    person_id desc;