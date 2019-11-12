/*
https://www.nowcoder.com/practice/355036f7f0c8429a85281f7ac05b457a
*/
select "select count(*) from " || name || ";" as cnts
from sqlite_master
where type = 'table';