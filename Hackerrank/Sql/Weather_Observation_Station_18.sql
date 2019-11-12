/*
Enter your query here.
*/
set @a = (select min(lat_n)
          from station);
set @b = (select min(long_w)
          from station);
set @c = (select max(lat_n)
          from station);
set @d = (select max(long_w)
          from station);
select round(abs(@a - @c) + abs(@b - @d), 4);