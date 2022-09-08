# Write your MySQL query statement below

SELECT  e1.name AS employee 
FROM Employee e1
JOIN employee e2 ON e1.managerId = e2.id 
AND e1.salary > e2.salary ; 
