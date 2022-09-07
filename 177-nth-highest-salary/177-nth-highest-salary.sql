CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN

/*
The limit option allows you to limit the number of rows returned 
from a query, while offset allows you to omit a specified number 
of rows before the beginning of the result set.
*/

SET N = N-1 ; 
  RETURN (
     
      SELECT DISTINCT(salary) 
      FROM Employee
      ORDER BY salary Desc LIMIT 1 OFFSET N 
  );
END