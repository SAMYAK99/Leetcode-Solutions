# Write your MySQL query statement below

SELECT name AS Customers FROM Customers cc
where id not in (SELECT  customerId from orders) ; 