/*
https://www.nowcoder.com/practice/aeaa116185f24f209ca4fa40e226de48
*/
drop table audit;
create table audit(
    emp_no int not null,
    create_date datetime not null,
    foreign key(emp_no) references employees_test(id));