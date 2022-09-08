# Write your MySQL query statement below

SELECT  email  FROM person
GROUP BY email having count(email) > 1;
