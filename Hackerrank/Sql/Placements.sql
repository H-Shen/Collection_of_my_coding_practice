/*
Enter your query here.
*/
select Students.name
from Students,
     Friends,
     Packages
where Students.id = Friends.id
  and Friends.friend_id = Packages.id
  and Packages.salary > (select Packages.salary from Packages where Packages.id = Students.id)
order by Packages.salary;