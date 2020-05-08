/*
Enter your query here.
*/
/* Do use limit 1 since there may be multiple long_ws with the same minimum lat_n */
select round(long_w, 4)
from station
where lat_n = (select min(lat_n) from station where lat_n > 38.7780)
order by lat_n;