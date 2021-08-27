CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE myOffset Int;
  SET myOffset = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct(Salary) from Employee order by Salary desc limit 1 offset myOffset
  );
END