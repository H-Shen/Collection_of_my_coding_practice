/*
https://www.nowcoder.com/practice/b9db784b5e3d488cbd30bd78fdb2a862
*/
create view if not exists actor_name_view
    (first_name_v, last_name_v)
as
select first_name, last_name
from actor;