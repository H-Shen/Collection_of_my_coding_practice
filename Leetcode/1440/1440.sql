# Write your MySQL query statement below
select t1.left_operand, t1.operator, t1.right_operand,
case
    when t1.operator = '>' and t2.v1v > t2.v2v then 'true'
    when t1.operator = '<' and t2.v1v < t2.v2v then 'true'
    when t1.operator = '=' and t2.v1v = t2.v2v then 'true'
    else 'false'
end as value
from Expressions as t1,

(select e.left_operand, e.operator, e.right_operand, v1.value as v1v, v2.value as v2v from Expressions as e, Variables as v1, Variables as v2
where e.left_operand = v1.name and e.right_operand = v2.name) as t2
where (t1.left_operand, t1.operator, t1.right_operand) = (t2.left_operand, t2.operator, t2.right_operand);