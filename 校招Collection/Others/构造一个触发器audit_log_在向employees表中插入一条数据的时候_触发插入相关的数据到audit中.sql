/*
https://www.nowcoder.com/practice/7e920bb2e1e74c4e83750f5c16033e2e
*/
create trigger if not exists audit_log
    after insert
    on employees_test
begin
    insert into audit values (new.id, new.name);
end;