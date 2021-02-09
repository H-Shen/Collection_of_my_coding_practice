# Write your MySQL query statement below
select a.Name as Customers from Customers as a where a.id not in (select b.CustomerId from Orders as b);
