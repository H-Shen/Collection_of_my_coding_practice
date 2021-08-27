# Write your MySQL query statement below
select b.seller_name from Seller as b where b.seller_id not in
(select a.seller_id from Orders as a where a.sale_date between '2020-01-01' and '2020-12-31') order by b.seller_name;