# Write your MySQL query statement below
select name from salesperson where name not in
                                   (
                                       select x.name
                                       from salesperson as x
                                                inner join
                                                (select com_id, sales_id from orders) as y
                                                on x.sales_id = y.sales_id
                                                inner join
                                                (select com_id, name from company) as z
                                                on y.com_id = z.com_id and z.name = 'RED'
                                   );