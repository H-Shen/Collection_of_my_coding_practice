# Write your MySQL query statement below
select y.name, x.balance from (select account, sum(amount) as balance from Transactions group by account) as x
inner join (select account, name from Users) as y
on y.account = x.account
where
x.balance > 10000;
