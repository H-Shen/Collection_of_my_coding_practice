/*
Enter your query here.
*/
set @a = (select min(lat_n)
          from station);
set @b = (select max(lat_n)
          from station);
set @c = (select min(long_w)
          from station);
set @d = (select max(long_w)
          from station);
select format(sqrt(pow(@a - @b, 2) + pow(@c - @d, 2)), 4);