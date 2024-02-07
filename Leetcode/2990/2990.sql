# Write your MySQL query statement below
select distinct user_id from Loans
where user_id in
(select user_id from Loans where loan_type = "Refinance"
intersect
(select user_id from Loans where loan_type = "Mortgage"))
order by
user_id;