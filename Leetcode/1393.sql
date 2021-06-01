# Write your MySQL query statement below
select y.stock_name, sum(y.newPrice) as capital_gain_loss from
(select x.stock_name, x.newPrice from
(select stock_name,
       IF(operation = 'Sell', price, price * (-1)) as newPrice
from Stocks) as x) as y
group by y.stock_name;