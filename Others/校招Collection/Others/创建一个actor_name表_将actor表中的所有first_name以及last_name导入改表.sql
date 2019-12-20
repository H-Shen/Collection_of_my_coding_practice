/*
https://www.nowcoder.com/practice/881385f388cf4fe98b2ed9f8897846df
*/
create table actor_name
(
    first_name varchar(45) not null,
    last_name  varchar(45) not null
);

insert into actor_name
select first_name, last_name
from actor;