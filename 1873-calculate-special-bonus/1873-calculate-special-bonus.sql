# Write your MySQL query statement below

/*
USE IF IN SQL
IF(condition, value_if_true, value_if_false)
*/

SELECT employee_id,
IF (employee_id%2 AND name not like "M%", salary, 0) as bonus
FROM Employees order by employee_id;
