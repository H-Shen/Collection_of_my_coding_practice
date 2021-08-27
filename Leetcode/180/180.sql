# Write your MySQL query statement below
select distinct l1.num as ConsecutiveNums from Logs as l1, Logs as l2, Logs as l3
where l2.id = l1.id+1 and l3.id = l2.id+1 and l1.Num = l2.Num and l2.Num = l3.Num;