# Write your MySQL query statement below
select count(account_id) as accounts_count
from Subscriptions
where year(start_date) <= 2021
  and year(end_date) >= 2021
  and account_id not in (select account_id from Streams where year(stream_date) = 2021)